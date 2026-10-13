#include <stdio.h>
#include <string.h>
#include <ctype.h>

void otpProcess(const char *in, char *out, const int *key, int mode) {
    int k = 0, i;
    for (i = 0; in[i]; i++) {
        if (isalpha((unsigned char)in[i])) {
            int base = isupper((unsigned char)in[i]) ? 'A' : 'a';
            out[i] = base + (in[i] - base + mode * key[k++] + 26) % 26;
        } else {
            out[i] = in[i];
        }
    }
    out[i] = '\0';
}

int main(void) {
    const char *plaintext = "send more money";
    int keyStream[13] = {3, 19, 5, 9, 0, 1, 7, 23, 15, 21, 14, 11, 2};
    char cipher[64], plain[64];

    otpProcess(plaintext, cipher, keyStream, 1);
    otpProcess(cipher, plain, keyStream, -1);

    printf("One-Time Pad Vigenere Stream Cipher\n");
    printf("Plaintext  : %s\n", plaintext);
    printf("Key Stream : ");
    for (int i = 0; i < 13; i++) printf("%d ", keyStream[i]);
    printf("\nCiphertext : %s\n", cipher);
    printf("Decrypted  : %s\n", plain);
    return 0;
}
