#include <stdio.h>
#include <stdint.h>

uint8_t blockCipherEnc(uint8_t block, uint8_t key) {
    return ((block ^ key) * 37 + 19) & 0xFF;
}

/* Compute CBC-MAC with IV = 0 */
uint8_t cbcMac(const uint8_t *msg, int numBlocks, uint8_t key) {
    uint8_t tag = 0;                     /* IV = 0 */
    for (int i = 0; i < numBlocks; i++)
        tag = blockCipherEnc(msg[i] ^ tag, key);
    return tag;
}

int main(void) {
    uint8_t secretKey = 0x7B;
    uint8_t X = 0x41;                    /* 1-block message X */

    /* Legitimate tag T = MAC(K, X) */
    uint8_t T = cbcMac(&X, 1, secretKey);

    /* Adversary constructs 2-block forged message: M' = X || (X ^ T) without knowing K */
    uint8_t forged[2] = { X, (uint8_t)(X ^ T) };
    uint8_t forgedTag = cbcMac(forged, 2, secretKey);

    printf("CBC-MAC Variable-Length Forgery Attack\n");
    printf("1-Block Message X          : 0x%02X\n", X);
    printf("Valid Tag T = MAC(K, X)    : 0x%02X\n\n", T);
    printf("Adversary forges 2-block message: X || (X ^ T) = [0x%02X, 0x%02X]\n", forged[0], forged[1]);
    printf("CBC-MAC of 2-block forgery : 0x%02X (Matches T = 0x%02X!)\n", forgedTag, T);
    return 0;
}
