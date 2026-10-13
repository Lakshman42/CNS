#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Standard English letter frequencies (%) */
const double engFreq[26] = {
    8.17, 1.49, 2.78, 4.25, 12.70, 2.23, 2.02, 6.09, 6.97, 0.15,
    0.77, 4.03, 2.41, 6.75, 7.51, 1.93, 0.10, 5.99, 6.33, 9.06,
    2.76, 0.98, 2.36, 0.15, 1.97, 0.07
};

typedef struct {
    int key;
    double score;
    char text[1024];
} Candidate;

int main(void) {
    char cipher[1024];
    int topN = 10;

    printf("Enter ciphertext: ");
    fgets(cipher, sizeof(cipher), stdin);
    cipher[strcspn(cipher, "\n")] = '\0';

    printf("How many top plaintexts to display (1-26)? ");
    if (scanf("%d", &topN) != 1 || topN < 1 || topN > 26) topN = 10;

    Candidate list[26];
    for (int k = 0; k < 26; k++) {
        list[k].key = k;
        list[k].score = 0.0;
        int i;
        for (i = 0; cipher[i]; i++) {
            char c = cipher[i];
            if (isalpha((unsigned char)c)) {
                int p = (toupper(c) - 'A' - k + 26) % 26;
                list[k].text[i] = isupper((unsigned char)c) ? ('A' + p) : ('a' + p);
                list[k].score += engFreq[p];
            } else {
                list[k].text[i] = c;
            }
        }
        list[k].text[i] = '\0';
    }

    /* Sort candidates in descending order of English frequency correlation score */
    for (int i = 0; i < 25; i++)
        for (int j = i + 1; j < 26; j++)
            if (list[j].score > list[i].score) {
                Candidate tmp = list[i]; list[i] = list[j]; list[j] = tmp;
            }

    printf("\nRank | Key | Score  | Candidate Plaintext\n");
    printf("-----+-----+--------+--------------------\n");
    for (int i = 0; i < topN; i++)
        printf(" %2d  | %2d  | %6.2f | %s\n", i + 1, list[i].key, list[i].score, list[i].text);

    return 0;
}
