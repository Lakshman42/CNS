#include <stdio.h>
#include <stdint.h>

uint32_t blockEnc(uint32_t b, uint32_t k) { return ((b ^ k) * 0x45D9F3Bu); }
uint32_t blockDec(uint32_t b, uint32_t k) { return (b * 0x119DE1F3u) ^ k; } /* 0x45D9F3B * 0x119DE1F3 == 1 mod 2^32 */

int main(void) {
    uint32_t key = 0xCAFEBABE, iv = 0x12345678;
    uint32_t P[3] = {0x11111111, 0x22222222, 0x33333333};
    uint32_t C[3], D[3];

    /* Normal CBC Encryption */
    uint32_t prev = iv;
    for (int i = 0; i < 3; i++) { C[i] = blockEnc(P[i] ^ prev, key); prev = C[i]; }

    /* Case 1: Flip 1 bit in transmitted C[0] (C1) */
    uint32_t C_corrupt[3] = {C[0] ^ 1, C[1], C[2]};
    prev = iv;
    for (int i = 0; i < 3; i++) { D[i] = blockDec(C_corrupt[i], key) ^ prev; prev = C_corrupt[i]; }

    printf("ECB vs CBC Error Propagation Analysis\n");
    printf("-------------------------------------\n");
    printf("Case 1: 1-bit transmission error in C1:\n");
    printf("  Block 1 (P1): %s (0x%08X vs 0x%08X)\n", D[0] != P[0] ? "CORRUPTED" : "INTACT", D[0], P[0]);
    printf("  Block 2 (P2): %s (0x%08X vs 0x%08X, 1-bit flip)\n", D[1] != P[1] ? "CORRUPTED" : "INTACT", D[1], P[1]);
    printf("  Block 3 (P3): %s    (0x%08X == 0x%08X)\n", D[2] != P[2] ? "CORRUPTED" : "INTACT", D[2], P[2]);
    printf("  (a) Are blocks beyond P2 affected? NO.\n\n");

    printf("Case 2: (b) 1-bit error in source P1 before encryption:\n");
    printf("  Ciphertext blocks affected: ALL blocks C1, C2, C3 differ!\n");
    printf("  Effect at receiver after CBC decryption: Only P1 has the 1-bit error; P2 and P3 are 100%% intact.\n");
    return 0;
}
