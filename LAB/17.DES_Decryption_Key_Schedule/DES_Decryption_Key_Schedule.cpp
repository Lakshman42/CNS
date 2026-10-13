#include <stdio.h>
#include <stdint.h>

/* Encryption left-shift schedule: rounds 1, 2, 9, 16 shift by 1; others by 2.
   For decryption (generating K16, K15, ..., K1 on the fly via RIGHT rotations
   starting from C0, D0), the right-shift schedule is:
   Round 1: 0 bits (since C16 == C0 after 28 total left shifts!)
   Rounds 2, 9, 16: 1 bit right shift; all other rounds: 2 bits right shift. */
const int decRightShifts[16] = {
    0, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1
};

uint32_t rotr28(uint32_t val, int s) {
    val &= 0x0FFFFFFF;
    return ((val >> s) | (val << (28 - s))) & 0x0FFFFFFF;
}

int main(void) {
    uint32_t C = 0x0F0F0F0;
    uint32_t D = 0x0AA55AA;

    printf("DES Decryption Key Schedule (Reverse Order K16 -> K1)\n");
    printf("Initial 28-bit halves: C0 = 0x%07X, D0 = 0x%07X\n\n", C, D);

    for (int r = 0; r < 16; r++) {
        C = rotr28(C, decRightShifts[r]);
        D = rotr28(D, decRightShifts[r]);
        printf("Decryption Round %2d (uses K%-2d, right shift %d): C = 0x%07X, D = 0x%07X\n",
               r + 1, 16 - r, decRightShifts[r], C, D);
    }
    return 0;
}
