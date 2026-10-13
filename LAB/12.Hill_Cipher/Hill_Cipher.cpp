#include <stdio.h>
#include <string.h>
#include <ctype.h>

int mod26(int x) {
    return ((x % 26) + 26) % 26;
}

int modInverse(int a) {
    a = mod26(a);
    for (int i = 1; i < 26; i++)
        if ((a * i) % 26 == 1) return i;
    return -1;
}

void hillProcess(const char *in, char *out, int K[2][2]) {
    int len = strlen(in);
    for (int i = 0; i < len; i += 2) {
        int p0 = in[i] - 'A';
        int p1 = in[i + 1] - 'A';
        out[i]     = 'A' + mod26(K[0][0] * p0 + K[0][1] * p1);
        out[i + 1] = 'A' + mod26(K[1][0] * p0 + K[1][1] * p1);
    }
    out[len] = '\0';
}

int main(void) {
    int K[2][2] = {{9, 4}, {5, 7}};
    int det = mod26(K[0][0] * K[1][1] - K[0][1] * K[1][0]);
    int detInv = modInverse(det);

    int Kinv[2][2];
    Kinv[0][0] = mod26( detInv * K[1][1]);
    Kinv[0][1] = mod26(-detInv * K[0][1]);
    Kinv[1][0] = mod26(-detInv * K[1][0]);
    Kinv[1][1] = mod26( detInv * K[0][0]);

    const char *raw = "meet me at the usual place at ten rather than eight oclock";
    char clean[256], cipher[256], plain[256];
    int n = 0;
    for (int i = 0; raw[i]; i++)
        if (isalpha((unsigned char)raw[i]))
            clean[n++] = toupper(raw[i]);
    if (n % 2 != 0) clean[n++] = 'X';
    clean[n] = '\0';

    hillProcess(clean, cipher, K);
    hillProcess(cipher, plain, Kinv);

    printf("Hill Cipher (2x2 Key Matrix)\n");
    printf("Key Matrix K = [ [%d, %d], [%d, %d] ]\n", K[0][0], K[0][1], K[1][0], K[1][1]);
    printf("det(K) = %d (mod 26), det^-1 = %d (mod 26)\n", det, detInv);
    printf("Inverse Matrix K^-1 = [ [%d, %d], [%d, %d] ]\n\n", Kinv[0][0], Kinv[0][1], Kinv[1][0], Kinv[1][1]);

    printf("Original Plaintext : %s\n", raw);
    printf("Cleaned Plaintext  : %s\n", clean);
    printf("(a) Encrypted Text : %s\n", cipher);
    printf("(b) Decrypted Text : %s\n", plain);
    return 0;
}
