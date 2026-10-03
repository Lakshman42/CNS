#include <stdio.h>
#include <string.h>
#include <ctype.h>

int gcd(int x, int y) {
    while (y) { int t = x % y; x = y; y = t; }
    return x;
}

/* Find a^-1 mod 26 such that (a * inv) % 26 == 1 */
int modInverse(int a) {
    for (int i = 1; i < 26; i++)
        if ((a * i) % 26 == 1) return i;
    return -1;
}

/* C = (a*p + b) mod 26 */
void encrypt(const char *in, char *out, int a, int b) {
    int i;
    for (i = 0; in[i]; i++) {
        char c = in[i];
        if (isalpha((unsigned char)c)) {
            int base = isupper((unsigned char)c) ? 'A' : 'a';
            out[i] = base + (a * (c - base) + b) % 26;
        } else out[i] = c;
    }
    out[i] = '\0';
}

/* P = a^-1 * (C - b) mod 26 */
void decrypt(const char *in, char *out, int a, int b) {
    int inv = modInverse(a);
    int i;
    for (i = 0; in[i]; i++) {
        char c = in[i];
        if (isalpha((unsigned char)c)) {
            int base = isupper((unsigned char)c) ? 'A' : 'a';
            out[i] = base + (inv * (c - base - b + 26)) % 26;
        } else out[i] = c;
    }
    out[i] = '\0';
}

int main(void) {
    int a, b;
    char text[1024], cipher[1024], plain[1024];

    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);

    if (gcd(a, 26) != 1) {
        printf("Invalid a! gcd(a, 26) must be 1, so the cipher would not be one-to-one.\n");
        printf("Allowed values of a: 1 3 5 7 9 11 15 17 19 21 23 25\n");
        return 1;
    }
    b = ((b % 26) + 26) % 26;             /* normalise b into 0..25 */

    getchar();                            /* consume leftover newline */
    printf("Enter plaintext: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    encrypt(text, cipher, a, b);
    printf("Ciphertext     : %s\n", cipher);

    decrypt(cipher, plain, a, b);
    printf("Decrypted text : %s\n", plain);
    return 0;
}
