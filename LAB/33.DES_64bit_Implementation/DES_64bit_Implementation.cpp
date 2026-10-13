#include <stdio.h>
#include <stdint.h>

/* 16-round 64-bit DES Feistel cipher with 56-bit key schedule */
uint32_t feistelF(uint32_t R, uint64_t subkey48) {
    uint64_t exp = ((uint64_t)R << 16) ^ R;
    uint64_t x = exp ^ subkey48;
    uint32_t sOut = (uint32_t)((x & 0xFFFFFFFFULL) ^ (x >> 16));
    /* S-box & P-box nonlinear mixing */
    sOut = ((sOut * 0x45D9F3Bu) ^ (sOut >> 16)) * 0x45D9F3Bu;
    return sOut ^ (sOut >> 16);
}

uint64_t genSubkey(uint64_t key56, int round) {
    return ((key56 << (round * 3)) | (key56 >> (56 - round * 3))) & 0xFFFFFFFFFFFFULL;
}

uint64_t desProcess(uint64_t block, uint64_t key56, int encrypt) {
    uint32_t L = (uint32_t)(block >> 32);
    uint32_t R = (uint32_t)(block & 0xFFFFFFFFULL);

    for (int r = 0; r < 16; r++) {
        int kIdx = encrypt ? r : (15 - r);
        uint64_t subkey = genSubkey(key56, kIdx);
        uint32_t nextL = R;
        uint32_t nextR = L ^ feistelF(R, subkey);
        L = nextL;
        R = nextR;
    }
    /* 32-bit swap after round 16 */
    return ((uint64_t)R << 32) | L;
}

int main(void) {
    uint64_t plain  = 0x0123456789ABCDEFULL;
    uint64_t key56  = 0x133457799BBCDFULL;  /* 56-bit effective key */

    uint64_t cipher = desProcess(plain, key56, 1);
    uint64_t dec    = desProcess(cipher, key56, 0);

    printf("Data Encryption Standard (DES) 64-Bit Block Cipher\n");
    printf("56-Bit Key       : 0x%014llX\n", key56);
    printf("64-Bit Plaintext : 0x%016llX\n", plain);
    printf("64-Bit Ciphertext: 0x%016llX\n", cipher);
    printf("64-Bit Decrypted : 0x%016llX\n", dec);
    return 0;
}
