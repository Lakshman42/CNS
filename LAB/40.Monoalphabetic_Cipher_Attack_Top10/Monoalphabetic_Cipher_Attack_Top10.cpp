#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char *engFreqOrder = "ETAOINSHRDLCUMWFGYPBVKJXQZ";

int main(void) {
    char cipher[1024];
    int topN = 10;

    printf("Enter monoalphabetic ciphertext: ");
    fgets(cipher, sizeof(cipher), stdin);
    cipher[strcspn(cipher, "\n")] = '\0';

    printf("Enter number of top plaintexts (e.g. 10): ");
    if (scanf("%d", &topN) != 1 || topN < 1 || topN > 10) topN = 10;

    int cnt[26] = {0}, ord[26];
    for (int i = 0; i < 26; i++) ord[i] = i;
    for (int i = 0; cipher[i]; i++)
        if (isalpha((unsigned char)cipher[i]))
            cnt[toupper(cipher[i]) - 'A']++;

    for (int i = 0; i < 25; i++)
        for (int j = i + 1; j < 26; j++)
            if (cnt[ord[j]] > cnt[ord[i]]) {
                int t = ord[i]; ord[i] = ord[j]; ord[j] = t;
            }

    printf("\nTop %d Ranked Plaintexts:\n", topN);
    for (int k = 0; k < topN; k++) {
        char rankMap[27];
        strcpy(rankMap, engFreqOrder);
        if (k > 0) { char t = rankMap[k - 1]; rankMap[k - 1] = rankMap[k]; rankMap[k] = t; }
        char sub[26];
        for (int i = 0; i < 26; i++) sub[ord[i]] = rankMap[i];

        printf("  Rank %2d: ", k + 1);
        for (int i = 0; cipher[i]; i++)
            putchar(isalpha((unsigned char)cipher[i]) ? sub[toupper(cipher[i]) - 'A'] : cipher[i]);
        printf("\n");
    }
    return 0;
}
