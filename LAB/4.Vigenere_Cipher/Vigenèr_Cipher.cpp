#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Keep only letters of the key, in uppercase. Returns its length. */
int cleanKey(const char *key, char *out) {
    int n = 0;
    for (int i = 0; key[i]; i++)
        if (isalpha((unsigned char)key[i]))
            out[n++] = toupper(key[i]);
    out[n] = '\0';
    return n;
}

/* mode = 1 encrypts, mode = -1 decrypts */
void vigenere(const char *in, char *out, const char *key, int klen, int mode) {
    int k = 0;                            /* advances only on letters */
    int i;
    for (i = 0; in[i]; i++) {
        char c = in[i];
        if (isalpha((unsigned char)c)) {
            int base  = isupper((unsigned char)c) ? 'A' : 'a';
            int shift = (key[k % klen] - 'A') * mode;
            out[i] = base + ((c - base + shift + 26) % 26);
            k++;
        } else {
            out[i] = c;                   /* keep spaces, digits, punctuation */
        }
    }
    out[i] = '\0';
}

int main(void) {
    char rawKey[64], key[64], text[1024], cipher[1024], plain[1024];

    printf("Enter key (letters only): ");
    scanf("%63s", rawKey);
    int klen = cleanKey(rawKey, key);
    if (klen == 0) {
        printf("Invalid key! It must contain at least one letter.\n");
        return 1;
    }

    getchar();                            /* consume leftover newline */
    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    vigenere(text, cipher, key, klen, 1);
    printf("Ciphertext     : %s\n", cipher);

    vigenere(cipher, plain, key, klen, -1);
    printf("Decrypted text : %s\n", plain);

    return 0;
}
