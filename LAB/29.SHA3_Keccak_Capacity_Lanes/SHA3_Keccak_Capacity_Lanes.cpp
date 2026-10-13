#include <stdio.h>
#include <stdint.h>

/* SHA-3 state has 25 lanes (5x5 matrix of 64-bit words = 1600 bits).
   Block size (rate r) = 1024 bits -> 1024 / 64 = 16 rate lanes.
   Capacity c = 1600 - 1024 = 576 bits -> 576 / 64 = 9 capacity lanes (initially all 0).
   In each Keccak round, the Theta (θ) step XORs each column's parity into every lane
   of that column, spreading nonzero bits from the 16 rate lanes into the 9 capacity lanes. */
int main(void) {
    uint64_t state[5][5] = {0};

    /* First 16 lanes (rate portion) have at least one nonzero bit; last 9 (capacity) are 0 */
    int lane = 0;
    for (int y = 0; y < 5; y++)
        for (int x = 0; x < 5; x++)
            if (lane++ < 16) state[x][y] = 1ULL;

    printf("SHA-3 (1600-bit state, Rate r = 1024 bits [16 lanes], Capacity c = 576 bits [9 lanes])\n");
    printf("Initial state: 16 rate lanes nonzero, 9 capacity lanes all zero.\n\n");

    /* Apply Theta (θ) column-parity mixing step of Round 1 */
    uint64_t C[5], D[5];
    for (int x = 0; x < 5; x++)
        C[x] = state[x][0] ^ state[x][1] ^ state[x][2] ^ state[x][3] ^ state[x][4];
    for (int x = 0; x < 5; x++)
        D[x] = C[(x + 4) % 5] ^ ((C[(x + 1) % 5] << 1) | (C[(x + 1) % 5] >> 63));
    for (int x = 0; x < 5; x++)
        for (int y = 0; y < 5; y++)
            state[x][y] ^= D[x];

    int zeroCapLanes = 0;
    lane = 0;
    for (int y = 0; y < 5; y++)
        for (int x = 0; x < 5; x++)
            if (lane++ >= 16 && state[x][y] == 0) zeroCapLanes++;

    printf("After the very first step (Theta) of Round 1:\n");
    printf("  Remaining all-zero capacity lanes = %d (out of 9)\n", zeroCapLanes);
    printf("  Conclusion: All 9 capacity lanes become nonzero after just 1 round (in the Theta step).\n");
    return 0;
}
