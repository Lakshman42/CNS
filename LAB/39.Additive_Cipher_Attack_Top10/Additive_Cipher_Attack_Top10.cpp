#include <stdio.h>
#include <string.h>
#include <ctype.h>

const double freq[26] = {
    8.17,1.49,2.78,4.25,12.70,2.23,2.02,6.09,6.97,0.15,
    0.77,4.03,2.41,6.75,7.51,1.93,0.10,5.99,6.33,9.06,
    2.76,0.98,2.36,0.15,1.97,0.07
};

int main(void) {
    char cipher[1024], plain[26][1024];
    double score[26] = {0};
    int order[26], topN = 10;

    printf("Enter additive ciphertext: ");
    fgets(cipher, sizeof(cipher), stdin);
    cipher[strcspn(cipher, "\n")] = '\0';

    printf("Enter number of top plaintexts (e.g. 10): ");
    if (scanf("%d", &topN) != 1 || topN < 1 || topN > 26) topN = 10;

    for (int k = 0; k < 26; k++) {
        order[k] = k;
        int i;
        for (i = 0; cipher[i]; i++) {
            if (isalpha((unsigned char)cipher[i])) {
                int p = (toupper(cipher[i]) - 'A' - k + 26) % 26;
                plain[k][i] = 'A' + p;
                score[k] += freq[p];
            } else plain[k][i] = cipher[i];
        }
        plain[k][i] = '\0';
    }

    for (int i = 0; i < 25; i++)
        for (int j = i + 1; j < 26; j++)
            if (score[order[j]] > score[order[i]]) {
                int t = order[i]; order[i] = order[j]; order[j] = t;
            }

    printf("\nTop %d Most Likely Plaintexts:\n", topN);
    for (int i = 0; i < topN; i++) {
        int k = order[i];
        printf("  #%2d (Key = %2d, Score = %6.2f): %s\n", i + 1, k, score[k], plain[k]);
    }
    return 0;
}
