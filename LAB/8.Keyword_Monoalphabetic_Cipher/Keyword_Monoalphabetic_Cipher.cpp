#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Build 26-letter cipher alphabet from keyword followed by unused letters */
void buildCipherAlphabet(const char *keyword, char *cipherAlpha) {
    int used[26] = {0};
    int idx = 0;

    for (int i = 0; keyword[i]; i++) {
        if (isalpha((unsigned char)keyword[i])) {
            int c = toupper(keyword[i]) - 'A';
            if (!used[c]) {
                used[c] = 1;
                cipherAlpha[idx++] = 'A' + c;
            }
        }
    }
    for (int c = 0; c < 26; c++) {
        if (!used[c])
            cipherAlpha[idx++] = 'A' + c;
    }
    cipherAlpha[26] = '\0';
}

void encrypt(const char *plain, char *cipher, const char *map) {
    int i;
    for (i = 0; plain[i]; i++) {
        char c = plain[i];
        if (isupper((unsigned char)c))
            cipher[i] = map[c - 'A'];
        else if (islower((unsigned char)c))
            cipher[i] = tolower(map[c - 'a']);
        else
            cipher[i] = c;
    }
    cipher[i] = '\0';
}

void decrypt(const char *cipher, char *plain, const char *map) {
    char inv[26];
    for (int i = 0; i < 26; i++)
        inv[map[i] - 'A'] = 'A' + i;

    int i;
    for (i = 0; cipher[i]; i++) {
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
    char keyword[64], map[27], text[1024], cipher[1024], plain[1024];

    printf("Enter keyword (e.g. CIPHER): ");
    scanf("%63s", keyword);
    buildCipherAlphabet(keyword, map);

    printf("Plain : a b c d e f g h i j k l m n o p q r s t u v w x y z\n");
    printf("Cipher: ");
    for (int i = 0; i < 26; i++) printf("%c%c", map[i], i == 25 ? '\n' : ' ');
    printf("\n");

    getchar();
    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    encrypt(text, cipher, map);
    printf("Ciphertext     : %s\n", cipher);

    decrypt(cipher, plain, map);
    printf("Decrypted text : %s\n", plain);
    return 0;
}
