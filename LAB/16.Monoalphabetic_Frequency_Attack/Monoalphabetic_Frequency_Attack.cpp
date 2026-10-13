#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* English letters ordered from most frequent to least frequent */
const char *engOrder = "ETAOINSHRDLCUMWFGYPBVKJXQZ";

int main(void) {
    char cipher[1024];
    int topN = 10;

    printf("Enter monoalphabetic ciphertext: ");
    fgets(cipher, sizeof(cipher), stdin);
    cipher[strcspn(cipher, "\n")] = '\0';

    printf("Enter number of top plaintexts (e.g. 10): ");
    if (scanf("%d", &topN) != 1 || topN < 1) topN = 10;

    int count[26] = {0}, order[26];
    for (int i = 0; i < 26; i++) order[i] = i;
    for (int i = 0; cipher[i]; i++)
        if (isalpha((unsigned char)cipher[i]))
            count[toupper(cipher[i]) - 'A']++;

    /* Sort ciphertext letters by frequency descending */
    for (int i = 0; i < 25; i++)
        for (int j = i + 1; j < 26; j++)
            if (count[order[j]] > count[order[i]]) {
                int t = order[i]; order[i] = order[j]; order[j] = t;
            }

    printf("\n");
    for (int k = 0; k < topN; k++) {
        char perm[27];
        strcpy(perm, engOrder);
        /* Swap adjacent frequency ranks to generate top N nearby candidates */
        if (k > 0 && k < 26) {
            char t = perm[k - 1]; perm[k - 1] = perm[k]; perm[k] = t;
        }
        char map[26];
        for (int i = 0; i < 26; i++)
            map[order[i]] = perm[i];

        printf("Rank %d: ", k + 1);
        for (int i = 0; cipher[i]; i++) {
            if (isalpha((unsigned char)cipher[i]))
                putchar(map[toupper(cipher[i]) - 'A']);
            else
                putchar(cipher[i]);
        }
        printf("\n");
    }
    return 0;
}
