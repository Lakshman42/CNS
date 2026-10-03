#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define N 5

char matrix[N][N];
int posR[26], posC[26];   /* row/col of each letter in the matrix */

/* Build the 5x5 matrix from the keyword */
void buildMatrix(const char *key) {
    int used[26] = {0};
    char seq[64];
    int len = 0;

    /* keyword letters first, then the rest of the alphabet */
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
        matrix[i / N][i % N] = seq[i];
        posR[seq[i] - 'A'] = i / N;
        posC[seq[i] - 'A'] = i % N;
    }
    posR['J' - 'A'] = posR['I' - 'A'];    /* J shares I's cell */
    posC['J' - 'A'] = posC['I' - 'A'];
}

void printMatrix(void) {
    printf("Playfair matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) printf("%c ", matrix[i][j]);
        printf("\n");
    }
}

/* Clean text and split into digraphs: insert 'X' between double letters,
   pad with 'X' if the length is odd */
int prepare(const char *text, char *out) {
    char clean[512];
    int n = 0;
    for (int i = 0; text[i]; i++) {
        if (!isalpha((unsigned char)text[i])) continue;
        char c = toupper(text[i]);
        clean[n++] = (c == 'J') ? 'I' : c;
    }

    int len = 0;
    for (int i = 0; i < n; i++) {
        out[len++] = clean[i];
        if (i + 1 < n && clean[i] == clean[i + 1])
            out[len++] = 'X';             /* split repeated letters */
    }
    if (len % 2) out[len++] = 'X';        /* pad last digraph */
    out[len] = '\0';
    return len;
}

/* shift = +1 to encrypt, 4 (i.e. -1 mod 5) to decrypt */
void process(const char *in, char *out, int shift) {
    int len = strlen(in);
    for (int i = 0; i < len; i += 2) {
        int a = in[i] - 'A', b = in[i + 1] - 'A';
        int r1 = posR[a], c1 = posC[a];
        int r2 = posR[b], c2 = posC[b];

        if (r1 == r2) {                   /* same row: move horizontally */
            out[i]     = matrix[r1][(c1 + shift) % N];
            out[i + 1] = matrix[r2][(c2 + shift) % N];
        } else if (c1 == c2) {            /* same column: move vertically */
            out[i]     = matrix[(r1 + shift) % N][c1];
            out[i + 1] = matrix[(r2 + shift) % N][c2];
        } else {                          /* rectangle: swap columns */
            out[i]     = matrix[r1][c2];
            out[i + 1] = matrix[r2][c1];
        }
    }
    out[len] = '\0';
}

int main(void) {
    char key[64], text[512], prepared[1024], cipher[1024], plain[1024];

    printf("Enter keyword: ");
    scanf("%63s", key);
    buildMatrix(key);
    printMatrix();

    getchar();                            /* consume leftover newline */
    printf("\nEnter plaintext: ");
    fgets(text, sizeof(text), stdin);

    prepare(text, prepared);
    printf("Prepared text  : %s\n", prepared);

    process(prepared, cipher, 1);
    printf("Ciphertext     : %s\n", cipher);

    process(cipher, plain, 4);
    printf("Decrypted text : %s\n", plain);

    return 0;
}
