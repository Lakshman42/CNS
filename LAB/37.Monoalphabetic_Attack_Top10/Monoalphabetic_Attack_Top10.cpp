#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char *eng = "ETAOINSHRDLCUMWFGYPBVKJXQZ";

int main(void) {
    char cipher[1024];
    int topN = 10;

    printf("Enter ciphertext: ");
    fgets(cipher, sizeof(cipher), stdin);
    cipher[strcspn(cipher, "\n")] = '\0';

    printf("Enter number of top plaintexts to show (up to 10): ");
    if (scanf("%d", &topN) != 1 || topN < 1 || topN > 10) topN = 10;

    int freq[26] = {0}, idx[26];
    for (int i = 0; i < 26; i++) idx[i] = i;
    for (int i = 0; cipher[i]; i++)
        if (isalpha((unsigned char)cipher[i]))
            freq[toupper(cipher[i]) - 'A']++;

    for (int i = 0; i < 25; i++)
        for (int j = i + 1; j < 26; j++)
            if (freq[idx[j]] > freq[idx[i]]) {
                int t = idx[i]; idx[i] = idx[j]; idx[j] = t;
            }

    printf("\nTop %d Candidate Plaintexts:\n", topN);
    for (int r = 0; r < topN; r++) {
        char target[27];
        strcpy(target, eng);
        if (r > 0) { char t = target[r - 1]; target[r - 1] = target[r]; target[r] = t; }
        char map[26];
        for (int i = 0; i < 26; i++) map[idx[i]] = target[i];

        printf("  #%2d: ", r + 1);
        for (int i = 0; cipher[i]; i++)
            putchar(isalpha((unsigned char)cipher[i]) ? map[toupper(cipher[i]) - 'A'] : cipher[i]);
        printf("\n");
    }
    return 0;
}
