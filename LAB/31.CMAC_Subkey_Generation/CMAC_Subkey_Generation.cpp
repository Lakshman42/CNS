#include <stdio.h>
#include <stdint.h>
#include <string.h>

/* Left-shift n-byte block by 1 bit; if MSB was 1, XOR last byte with Rb */
void deriveSubkey(const uint8_t *in, uint8_t *out, int nBytes, uint8_t Rb) {
    int msb = (in[0] & 0x80) != 0;
    for (int i = 0; i < nBytes - 1; i++)
        out[i] = (uint8_t)((in[i] << 1) | (in[i + 1] >> 7));
    out[nBytes - 1] = (uint8_t)(in[nBytes - 1] << 1);
    if (msb)
        out[nBytes - 1] ^= Rb;
}

void printHex(const char *label, const uint8_t *buf, int n) {
    printf("%s", label);
    for (int i = 0; i < n; i++) printf("%02X", buf[i]);
    printf("\n");
}

int main(void) {
    /* 128-bit example (NIST SP 800-38B test vector L = E(K, 0^128)) */
    uint8_t L128[16] = {
        0x7D,0xF7,0x6B,0x0C, 0x1A,0xB8,0x99,0xB3,
        0x3E,0x42,0xF0,0x47, 0xB9,0x1B,0x54,0x6F
    };
    uint8_t K1_128[16], K2_128[16];
    deriveSubkey(L128, K1_128, 16, 0x87);    /* R_128 = 0x87 */
    deriveSubkey(K1_128, K2_128, 16, 0x87);

    /* 64-bit example */
    uint8_t L64[8] = {0xE8,0xA2,0x13,0x9F, 0x44,0x10,0x7C,0x01};
    uint8_t K1_64[8], K2_64[8];
    deriveSubkey(L64, K1_64, 8, 0x1B);       /* R_64 = 0x1B */
    deriveSubkey(K1_64, K2_64, 8, 0x1B);

    printf("CMAC Subkey Generation (K1, K2)\n");
    printf("(a) Polynomial Constants:\n");
    printf("    64-bit block  : R_64  = 0x000000000000001B (x^64 + x^4 + x^3 + x + 1)\n");
    printf("    128-bit block : R_128 = 0x00...0087        (x^128 + x^7 + x^2 + x + 1)\n\n");

    printf("128-bit Block Subkeys:\n");
    printHex("  L = E(K, 0^128) : ", L128, 16);
    printHex("  Subkey K1       : ", K1_128, 16);
    printHex("  Subkey K2       : ", K2_128, 16);

    printf("\n64-bit Block Subkeys:\n");
    printHex("  L = E(K, 0^64)  : ", L64, 8);
    printHex("  Subkey K1       : ", K1_64, 8);
    printHex("  Subkey K2       : ", K2_64, 8);
    return 0;
}
