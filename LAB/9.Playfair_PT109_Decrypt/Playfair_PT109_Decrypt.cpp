#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];
int posR[26], posC[26];

void buildMatrix(const char *key) {
    int used[26] = {0};
    char seq[26];
    int len = 0;

    for (int i = 0; key[i]; i++) {
        if (!isalpha((unsigned char)key[i])) continue;
        char c = toupper(key[i]);
        if (c == 'J') c = 'I';
        if (!used[c - 'A']) { used[c - 'A'] = 1; seq[len++] = c; }
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        if (c == 'J') continue;
        if (!used[c - 'A']) { used[c - 'A'] = 1; seq[len++] = c; }
    }
    for (int i = 0; i < 25; i++) {
        matrix[i / 5][i % 5] = seq[i];
        posR[seq[i] - 'A'] = i / 5;
        posC[seq[i] - 'A'] = i % 5;
    }
    posR['J' - 'A'] = posR['I' - 'A'];
    posC['J' - 'A'] = posC['I' - 'A'];
}

void decryptPlayfair(const char *cipher, char *plain) {
    char clean[256];
    int n = 0;
    for (int i = 0; cipher[i]; i++) {
        if (isalpha((unsigned char)cipher[i])) {
            char c = toupper(cipher[i]);
            clean[n++] = (c == 'J') ? 'I' : c;
        }
    }
    for (int i = 0; i < n; i += 2) {
        int a = clean[i] - 'A', b = clean[i + 1] - 'A';
        int r1 = posR[a], c1 = posC[a];
        int r2 = posR[b], c2 = posC[b];
        if (r1 == r2) {
            plain[i]     = matrix[r1][(c1 + 4) % 5];
            plain[i + 1] = matrix[r2][(c2 + 4) % 5];
        } else if (c1 == c2) {
            plain[i]     = matrix[(r1 + 4) % 5][c1];
            plain[i + 1] = matrix[(r2 + 4) % 5][c2];
        } else {
            plain[i]     = matrix[r1][c2];
            plain[i + 1] = matrix[r2][c1];
        }
    }
    plain[n] = '\0';
}

int main(void) {
    const char *key = "ROYAL NEW ZEALAND NAVY";
    const char *cipher =
        "KXJEY UREBE ZWEHE WRYTU HEYFS KREHE GOYFI WTTTU OLKSY CAJPO "
        "BOTEI ZONTX BYBNT GONEY CUZWR GDSON SXBOU YWRHE BAAHY USEDQ";
    char plain[256];

    buildMatrix(key);
    printf("PT-109 Playfair Decryption (Key: %s)\n", key);
    printf("Playfair 5x5 Matrix:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) printf("%c ", matrix[i][j]);
        printf("\n");
    }

    decryptPlayfair(cipher, plain);
    printf("\nCiphertext:\n%s\n\n", cipher);
    printf("Decrypted Message:\n%s\n", plain);
    return 0;
}
