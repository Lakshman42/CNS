#include <stdio.h>
#include <stdint.h>

/* Toy 64-bit Feistel block cipher representing single DES for 3DES EDE demonstration */
uint64_t desBlock(uint64_t block, uint64_t key, int enc) {
    uint32_t L = (uint32_t)(block >> 32), R = (uint32_t)(block & 0xFFFFFFFF);
    for (int r = 0; r < 16; r++) {
        int idx = enc ? r : (15 - r);
        uint32_t sub = (uint32_t)((key >> ((idx * 3) % 32)) ^ (idx * 0x9E3779B9u));
        uint32_t f = ((R ^ sub) * 0x85EBCA6Bu) ^ ((R >> 13) | (R << 19));
        uint32_t tmp = L ^ f;
        L = R; R = tmp;
    }
    return ((uint64_t)R << 32) | L;
}

uint64_t tdesEncrypt(uint64_t p, uint64_t k1, uint64_t k2, uint64_t k3) {
    return desBlock(desBlock(desBlock(p, k1, 1), k2, 0), k3, 1);
}

uint64_t tdesDecrypt(uint64_t c, uint64_t k1, uint64_t k2, uint64_t k3) {
    return desBlock(desBlock(desBlock(c, k3, 0), k2, 1), k1, 0);
}

int main(void) {
    uint64_t K1 = 0x133457799BBCDFF1ULL, K2 = 0x1122334455667788ULL, K3 = 0xAABBCCDDEEFF0011ULL;
    uint64_t IV = 0x0123456789ABCDEFULL;
    uint64_t P[2] = {0x5468652071756663ULL, 0x6B2062726F776E20ULL};
    uint64_t C[2], D[2];

    printf("3DES-CBC Encryption and Decryption\n");
    printf("Keys: K1 = 0x%016llX, K2 = 0x%016llX, K3 = 0x%016llX\n", K1, K2, K3);
    printf("IV  : 0x%016llX\n\n", IV);

    /* CBC Encryption: C_i = E(P_i ^ C_{i-1}) */
    uint64_t prev = IV;
    for (int i = 0; i < 2; i++) {
        C[i] = tdesEncrypt(P[i] ^ prev, K1, K2, K3);
        prev = C[i];
        printf("Plaintext Block %d : 0x%016llX  -> Ciphertext C%d : 0x%016llX\n", i + 1, P[i], i + 1, C[i]);
    }

    /* CBC Decryption: P_i = D(C_i) ^ C_{i-1} */
    prev = IV;
    for (int i = 0; i < 2; i++) {
        D[i] = tdesDecrypt(C[i], K1, K2, K3) ^ prev;
        prev = C[i];
        printf("Decrypted Block %d : 0x%016llX\n", i + 1, D[i]);
    }

    printf("\n(a) Security choice   : 3-key 3DES in outer CBC mode (168-bit key space).\n");
    printf("(b) Performance choice: AES-128/256 CBC (or 2-key 3DES when restricted to DES hardware).\n");
    return 0;
}
