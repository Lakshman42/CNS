#include <stdio.h>

int mod26(int x) { return ((x % 26) + 26) % 26; }

int main(void) {
    /* Secret Hill key matrix held by oracle */
    int secretK[2][2] = {{9, 4}, {5, 7}};

    /* Attacker mounts Chosen-Plaintext Attack using identity matrix P = [[1, 0], [0, 1]]
       Pair 1: "BA" = (1, 0)
       Pair 2: "AB" = (0, 1) */
    int P[2][2] = {{1, 0}, {0, 1}};
    int C[2][2];

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            C[i][j] = mod26(P[i][0] * secretK[0][j] + P[i][1] * secretK[1][j]);

    printf("Hill Cipher Chosen-Plaintext Attack\n");
    printf("Chosen Plaintext Matrix P = I = [ [1, 0 ('BA')], [0, 1 ('AB')] ]\n");
    printf("Oracle returns Ciphertext C   = [ [%d, %d ('%c%c')], [%d, %d ('%c%c')] ]\n\n",
           C[0][0], C[0][1], 'A' + C[0][0], 'A' + C[0][1],
           C[1][0], C[1][1], 'A' + C[1][0], 'A' + C[1][1]);
    printf("Since C = I * K = K, the secret key matrix K is directly revealed:\n");
    printf("  Recovered Key K = [ [%d, %d], [%d, %d] ]\n", C[0][0], C[0][1], C[1][0], C[1][1]);
    return 0;
}
