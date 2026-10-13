#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define BSIZE 8

int applyBitPadding(const uint8_t *msg, int len, uint8_t *out) {
    memcpy(out, msg, len);
    out[len] = 0x80;                     /* '1' bit followed by seven '0' bits */
    int paddedLen = ((len / BSIZE) + 1) * BSIZE;
    for (int i = len + 1; i < paddedLen; i++) out[i] = 0x00;
    return paddedLen;
}

int removeBitPadding(const uint8_t *padded, int paddedLen, uint8_t *out) {
    int idx = paddedLen - 1;
    while (idx >= 0 && padded[idx] == 0x00) idx--;
    if (idx >= 0 && padded[idx] == 0x80) {
        memcpy(out, padded, idx);
        return idx;
    }
    return paddedLen;
}

int main(void) {
    /* Message whose final byte legitimately ends in 0x80 */
    uint8_t msg[8] = {0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70, 0x80};
    uint8_t padded[16], recovered[16];

    int plen = applyBitPadding(msg, 8, padded);
    int rlen = removeBitPadding(padded, plen, recovered);

    printf("10* Padding Motivation Demonstration (ECB / CBC / CFB)\n");
    printf("Original 8-byte block ending in 0x80 : ");
    for (int i = 0; i < 8; i++) printf("%02X ", msg[i]);
    printf("\nPadded to 16 bytes (extra block)     : ");
    for (int i = 0; i < plen; i++) printf("%02X ", padded[i]);
    printf("\nRecovered after stripping padding    : ");
    for (int i = 0; i < rlen; i++) printf("%02X ", recovered[i]);
    printf("(%d bytes intact)\n", rlen);
    return 0;
}
