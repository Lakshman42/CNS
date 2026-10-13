#include <stdio.h>
#include <stdint.h>

const int P10[10] = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};
const int P8[8]   = {6, 3, 7, 4, 8, 5, 10, 9};
const int IP[8]   = {2, 6, 3, 1, 4, 8, 5, 7};
const int IPinv[8]= {4, 1, 3, 5, 7, 2, 8, 6};
const int EP[8]   = {4, 1, 2, 3, 2, 3, 4, 1};
const int P4[4]   = {2, 4, 3, 1};
const int S0[4][4] = {{1,0,3,2},{3,2,1,0},{0,2,1,3},{3,1,3,2}};
const int S1[4][4] = {{0,1,2,3},{2,0,1,3},{3,0,1,0},{2,1,0,3}};

int permute(int val, const int *p, int n, int inBits) {
    int out = 0;
    for (int i = 0; i < n; i++)
        out = (out << 1) | ((val >> (inBits - p[i])) & 1);
    return out;
}

int ls5(int v, int s) { return ((v << s) | (v >> (5 - s))) & 0x1F; }

void genKeys(int key10, uint8_t *K1, uint8_t *K2) {
    int p = permute(key10, P10, 10, 10);
    int L = ls5(p >> 5, 1), R = ls5(p & 0x1F, 1);
    *K1 = permute((L << 5) | R, P8, 8, 10);
    L = ls5(L, 2); R = ls5(R, 2);
    *K2 = permute((L << 5) | R, P8, 8, 10);
}

int fk(int val, uint8_t sk) {
    int L = (val >> 4) & 0xF, R = val & 0xF;
    int x = permute(R, EP, 8, 4) ^ sk;
    int x0 = (x >> 4) & 0xF, x1 = x & 0xF;
    int r0 = ((x0 & 8) >> 2) | (x0 & 1), c0 = (x0 >> 1) & 3;
    int r1 = ((x1 & 8) >> 2) | (x1 & 1), c1 = (x1 >> 1) & 3;
    int s = (S0[r0][c0] << 2) | S1[r1][c1];
    return ((L ^ permute(s, P4, 4, 4)) << 4) | R;
}

uint8_t sdesEnc(uint8_t p, uint8_t K1, uint8_t K2) {
    int b = permute(p, IP, 8, 8);
    b = fk(b, K1);
    b = ((b & 0xF) << 4) | (b >> 4);
    b = fk(b, K2);
    return permute(b, IPinv, 8, 8);
}

void printBin8(uint8_t b) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (b >> i) & 1);
        if (i == 4) printf(" ");
    }
}

int main(void) {
    int key10 = 0b0111111101;
    uint8_t P[3] = {0b00000001, 0b00000010, 0b00000100};
    uint8_t C[3], D[3], K1, K2;
    genKeys(key10, &K1, &K2);

    for (int i = 0; i < 3; i++) {
        uint8_t keystream = sdesEnc((uint8_t)i, K1, K2);
        C[i] = P[i] ^ keystream;
        D[i] = C[i] ^ keystream;
    }

    printf("S-DES in Counter (CTR) Mode\n");
    printf("10-bit Key     : 01111 11101\n");
    printf("Initial Counter: 0000 0000\n");
    printf("Plaintext      : ");
    for (int i = 0; i < 3; i++) { printBin8(P[i]); printf("  "); }
    printf("\nCiphertext     : ");
    for (int i = 0; i < 3; i++) { printBin8(C[i]); printf("  "); }
    printf("\nDecrypted      : ");
    for (int i = 0; i < 3; i++) { printBin8(D[i]); printf("  "); }
    printf("\n");
    return 0;
}
