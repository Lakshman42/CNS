#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define BLOCK_SIZE 8

/* Pad with 0x80 (10000000 in binary) followed by 0x00 bytes to next multiple of BLOCK_SIZE */
int padMessage(const uint8_t *in, int len, uint8_t *out) {
    memcpy(out, in, len);
    out[len] = 0x80;
    int total = ((len / BLOCK_SIZE) + 1) * BLOCK_SIZE;
    for (int i = len + 1; i < total; i++) out[i] = 0x00;
    return total;
}

int unpadMessage(const uint8_t *in, int total, uint8_t *out) {
    int i = total - 1;
    while (i >= 0 && in[i] == 0x00) i--;
    if (i >= 0 && in[i] == 0x80) {
        memcpy(out, in, i);
        out[i] = '\0';
        return i;
    }
    return total;
}

int main(void) {
    const uint8_t msg[8] = {'A','B','C','D','E','F','G','H'};
    uint8_t padded[16], ecb[16], cbc[16], cfb[16], recovered[16];
    uint8_t key = 0x5A, iv = 0xAA;

    int plen = padMessage(msg, 8, padded);

    printf("Block Cipher Modes (ECB, CBC, CFB) with 10* Bit Padding\n");
    printf("Original 8-byte aligned message (8 bytes): ");
    for (int i = 0; i < 8; i++) printf("%02X ", msg[i]);
    printf("\nPadded message (%d bytes with 0x80 00..00): ", plen);
    for (int i = 0; i < plen; i++) printf("%02X ", padded[i]);
    printf("\n\n");

    for (int i = 0; i < plen; i++) {
        ecb[i] = padded[i] ^ key;
        cbc[i] = (padded[i] ^ (i < 8 ? iv : cbc[i - 8])) ^ key;
        cfb[i] = padded[i] ^ ((i < 8 ? iv : cfb[i - 8]) ^ key);
    }

    printf("ECB Ciphertext : "); for (int i = 0; i < plen; i++) printf("%02X ", ecb[i]); printf("\n");
    printf("CBC Ciphertext : "); for (int i = 0; i < plen; i++) printf("%02X ", cbc[i]); printf("\n");
    printf("CFB Ciphertext : "); for (int i = 0; i < plen; i++) printf("%02X ", cfb[i]); printf("\n");

    int rlen = unpadMessage(padded, plen, recovered);
    printf("Unpadded Output: %s (%d bytes recovered unambiguously)\n", recovered, rlen);
    return 0;
}
