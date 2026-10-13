#include <stdio.h>

int mod26(int x) { return ((x % 26) + 26) % 26; }

int modInverse(int a) {
    a = mod26(a);
    for (int i = 1; i < 26; i++)
        if ((a * i) % 26 == 1) return i;
    return -1;
}

int main(void) {
    /* Known pairs from Program 12 (row-vector convention C = P * K mod 26):
       Pair 1: "TH" (19, 7)  -> "RO" (17, 14)
       Pair 2: "HE" (7, 4)   -> "AJ" (0, 9)   (or chosen plaintext P = [[1,0],[0,1]]) */
    int P[2][2] = {{19, 7}, {0, 19}};   /* "TH" and "AT" */
    int C[2][2] = {{17, 14}, {24, 3}};  /* "RO" and "YD" */

    int det = mod26(P[0][0] * P[1][1] - P[0][1] * P[1][0]);
    int detInv = modInverse(det);

    int Pinv[2][2];
    Pinv[0][0] = mod26( detInv * P[1][1]);
    Pinv[0][1] = mod26(-detInv * P[0][1]);
    Pinv[1][0] = mod26(-detInv * P[1][0]);
    Pinv[1][1] = mod26( detInv * P[0][0]);

    int K[2][2];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            K[i][j] = mod26(Pinv[i][0] * C[0][j] + Pinv[i][1] * C[1][j]);

    printf("Hill Cipher Known / Chosen Plaintext Attack\n");
    printf("Known Plaintext Digraphs : 'TH' (19, 7) and 'AT' (0, 19)\n");
    printf("Corresponding Ciphertext : 'RO' (17, 14) and 'YD' (24, 3)\n\n");
    printf("Plaintext Matrix P  = [ [%d, %d], [%d, %d] ], det(P) mod 26 = %d (inv = %d)\n",
           P[0][0], P[0][1], P[1][0], P[1][1], det, detInv);
    printf("Inverse Matrix P^-1 = [ [%d, %d], [%d, %d] ]\n",
           Pinv[0][0], Pinv[0][1], Pinv[1][0], Pinv[1][1]);
    printf("Recovered Key K = (P^-1 * C) mod 26 = [ [%d, %d], [%d, %d] ]\n",
           K[0][0], K[1][0], K[0][1], K[1][1]);
    return 0;
}
