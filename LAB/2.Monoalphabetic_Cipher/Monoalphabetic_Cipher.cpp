#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHA 26

/* Check that key has 26 letters, all unique */
int validKey(const char *key) {
    int seen[ALPHA] = {0};
    if (strlen(key) != ALPHA) return 0;
    for (int i = 0; i < ALPHA; i++) {
        if (!isalpha((unsigned char)key[i])) return 0;
        int idx = toupper(key[i]) - 'A';
        if (seen[idx]) return 0;          /* duplicate letter */
        seen[idx] = 1;
    }
    return 1;
}

/* Encrypt: plaintext letter -> key[letter] */
void encrypt(const char *plain, char *cipher, const char *key) {
    int i;
    for (i = 0; plain[i] != '\0'; i++) {
        char c = plain[i];
        if (isupper((unsigned char)c))
            cipher[i] = toupper(key[c - 'A']);
        else if (islower((unsigned char)c))
            cipher[i] = tolower(key[c - 'a']);
        else
            cipher[i] = c;                /* keep spaces, digits, punctuation */
    }
    cipher[i] = '\0';
}

/* Decrypt: build the inverse map, then substitute back */
void decrypt(const char *cipher, char *plain, const char *key) {
    char inv[ALPHA];
    for (int i = 0; i < ALPHA; i++)
        inv[toupper(key[i]) - 'A'] = 'A' + i;

    int i;
    for (i = 0; cipher[i] != '\0'; i++) {
        char c = cipher[i];
        if (isupper((unsigned char)c))
            plain[i] = inv[c - 'A'];
        else if (islower((unsigned char)c))
            plain[i] = tolower(inv[c - 'a']);
        else
            plain[i] = c;
    }
    plain[i] = '\0';
}

int main(void) {
    char key[64], text[1024], result[1024];

    printf("Enter 26-letter key (a permutation of A-Z): ");
    scanf("%63s", key);
    if (!validKey(key)) {
        printf("Invalid key! It must contain all 26 letters exactly once.\n");
        return 1;
    }

    printf("Plaintext alphabet : ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
    printf("Ciphertext alphabet: ");
    for (int i = 0; i < ALPHA; i++) putchar(toupper(key[i]));
    printf("\n\n");

    getchar();                            /* consume leftover newline */
    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    encrypt(text, result, key);
    printf("Ciphertext     : %s\n", result);

    char back[1024];
    decrypt(result, back, key);
    printf("Decrypted text : %s\n", back);

    return 0;
}
