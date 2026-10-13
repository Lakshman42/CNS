#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char matrix[5][5] = {
    {'M', 'F', 'H', 'I', 'K'},
    {'U', 'N', 'O', 'P', 'Q'},
    {'Z', 'V', 'W', 'X', 'Y'},
    {'E', 'L', 'A', 'R', 'G'},
    {'D', 'S', 'T', 'B', 'C'}
};

void findPos(char c, int *r, int *col) {
    if (c == 'J') c = 'I';
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (matrix[i][j] == c) { *r = i; *col = j; return; }
}

int prepare(const char *in, char *out) {
    char clean[256];
    int n = 0;
    for (int i = 0; in[i]; i++)
        if (isalpha((unsigned char)in[i])) {
            char c = toupper(in[i]);
            clean[n++] = (c == 'J') ? 'I' : c;
        }
    int len = 0;
    for (int i = 0; i < n; i++) {
        out[len++] = clean[i];
        if (i + 1 < n && clean[i] == clean[i + 1])
            out[len++] = 'X';
    }
    if (len % 2 != 0) out[len++] = 'X';
    out[len] = '\0';
    return len;
}

void encrypt(const char *prep, char *cipher) {
    int len = strlen(prep);
    for (int i = 0; i < len; i += 2) {
        int r1, c1, r2, c2;
        findPos(prep[i], &r1, &c1);
        findPos(prep[i + 1], &r2, &c2);
        if (r1 == r2) {
            cipher[i]     = matrix[r1][(c1 + 1) % 5];
            cipher[i + 1] = matrix[r2][(c2 + 1) % 5];
        } else if (c1 == c2) {
            cipher[i]     = matrix[(r1 + 1) % 5][c1];
            cipher[i + 1] = matrix[(r2 + 1) % 5][c2];
        } else {
            cipher[i]     = matrix[r1][c2];
            cipher[i + 1] = matrix[r2][c1];
        }
    }
    cipher[len] = '\0';
}

int main(void) {
    const char *msg = "Must see you over Cadogan West. Coming at once.";
    char prep[256], cipher[256];

    printf("Given Playfair Matrix:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) printf("%c ", matrix[i][j]);
        printf("\n");
    }

    int len = prepare(msg, prep);
    encrypt(prep, cipher);

    printf("\nOriginal Message : %s\n", msg);
    printf("Prepared Digraphs: ");
    for (int i = 0; i < len; i += 2) printf("%c%c ", prep[i], prep[i + 1]);
    printf("\nCiphertext       : ");
    for (int i = 0; i < len; i += 2) printf("%c%c ", cipher[i], cipher[i + 1]);
    printf("\n");
    return 0;
}
