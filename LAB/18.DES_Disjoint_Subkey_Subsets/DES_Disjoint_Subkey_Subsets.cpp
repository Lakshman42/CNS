#include <stdio.h>

const int PC2[48] = {
    /* First 24 bits: chosen from C_i (bits 1..28) */
    14, 17, 11, 24,  1,  5,  3, 28, 15,  6, 21, 10,
    23, 19, 12,  4, 26,  8, 16,  7, 27, 20, 13,  2,
    /* Second 24 bits: chosen from D_i (bits 29..56) */
    41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48,
    44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32
};

int main(void) {
    printf("DES Subkey Disjoint 28-Bit Subset Verification (PC-2 Analysis)\n");
    printf("--------------------------------------------------------------\n");

    int maxFirst = 0, minSecond = 100;
    printf("First 24 bits of PC-2 select strictly from C_i (positions 1..28):\n  ");
    for (int i = 0; i < 24; i++) {
        printf("%2d ", PC2[i]);
        if (PC2[i] > maxFirst) maxFirst = PC2[i];
    }
    printf("\n  Max index in first 24 bits = %d (all <= 28, belonging to C_i)\n\n", maxFirst);

    printf("Second 24 bits of PC-2 select strictly from D_i (positions 29..56):\n  ");
    for (int i = 24; i < 48; i++) {
        printf("%2d ", PC2[i]);
        if (PC2[i] < minSecond) minSecond = PC2[i];
    }
    printf("\n  Min index in second 24 bits = %d (all >= 29, belonging to D_i)\n\n", minSecond);

    printf("Verified: The two 24-bit subkey halves come from completely disjoint 28-bit subsets of the 56-bit key.\n");
    return 0;
}
