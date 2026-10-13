#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    const char *plainA = "send more money";
    int keyA[13] = {9, 0, 1, 7, 23, 15, 21, 14, 11, 11, 2, 8, 9};
    char cipher[64];

    int k = 0;
    for (int i = 0; plainA[i]; i++) {
        if (isalpha((unsigned char)plainA[i])) {
            int p = tolower(plainA[i]) - 'a';
            cipher[i] = 'a' + (p + keyA[k++]) % 26;
        } else {
            cipher[i] = plainA[i];
        }
    }
    cipher[strlen(plainA)] = '\0';

    printf("One-Time Pad Vigenere Cipher\n");
    printf("(a) Plaintext  : %s\n", plainA);
    printf("    Key Stream : ");
    for (int i = 0; i < 13; i++) printf("%d ", keyA[i]);
    printf("\n    Ciphertext : %s\n\n", cipher);

    /* Part (b): Find key K' such that cipher decrypts to "cash not needed" */
    const char *cipherLetters = "beokjdmsxzpmh";
    const char *targetPlain   = "cashnotneeded";
    int keyB[13];

    printf("(b) Target Text: cash not needed\n");
    printf("    New Key    : ");
    for (int i = 0; i < 13; i++) {
        int c = cipherLetters[i] - 'a';
        int p = targetPlain[i] - 'a';
        keyB[i] = (c - p + 26) % 26;
        printf("%d ", keyB[i]);
    }

    char verify[32];
    for (int i = 0; i < 13; i++)
        verify[i] = 'a' + (cipherLetters[i] - 'a' - keyB[i] + 26) % 26;
    verify[13] = '\0';
    printf("\n    Decrypted  : %.4s %.3s %.6s\n", verify, verify + 4, verify + 7);
    return 0;
}
