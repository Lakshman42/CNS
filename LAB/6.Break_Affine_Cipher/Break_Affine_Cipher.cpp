#include <stdio.h>
#include <string.h>
#include <ctype.h>

int gcd(int x, int y) {
    while (y) { int t = x % y; x = y; y = t; }
    return x;
}

int modInverse(int a) {
    a = ((a % 26) + 26) % 26;
    for (int i = 1; i < 26; i++)
        if ((a * i) % 26 == 1) return i;
    return -1;
}

/* Decrypt C using P = a^-1 * (C - b) mod 26 */
void decrypt(const char *cipher, char *plain, int a, int b) {
    int inv = modInverse(a);
    int i;
    for (i = 0; cipher[i]; i++) {
        char c = cipher[i];
        if (isalpha((unsigned char)c)) {
            int base = isupper((unsigned char)c) ? 'A' : 'a';
            plain[i] = base + (inv * ((c - base) - b + 26)) % 26;
        } else {
            plain[i] = c;
        }
    }
    plain[i] = '\0';
}

int main(void) {
    /* Most frequent English letters: E (4) and T (19)
       Most frequent ciphertext letters: B (1) and U (20)
       4a + b = 1 (mod 26)
       19a + b = 20 (mod 26)  => 15a = 19 (mod 26) */
    int p1 = 'E' - 'A', c1 = 'B' - 'A';
    int p2 = 'T' - 'A', c2 = 'U' - 'A';

    int diffP = (p2 - p1 + 26) % 26;
    int diffC = (c2 - c1 + 26) % 26;
    int a = (diffC * modInverse(diffP)) % 26;
    int b = (c1 - a * p1 % 26 + 26) % 26;

    printf("Affine Cipher Cryptanalysis (Most frequent: 'B', Second: 'U')\n");
    printf("Assuming 'B' (1) <- 'E' (4) and 'U' (20) <- 'T' (19):\n");
    printf("  4a + b = 1  (mod 26)\n");
    printf(" 19a + b = 20 (mod 26)\n");
    printf("Solved key: a = %d, b = %d (a^-1 mod 26 = %d)\n\n", a, b, modInverse(a));

    char cipher[1024], plain[1024];
    printf("Enter affine ciphertext to break: ");
    if (fgets(cipher, sizeof(cipher), stdin)) {
        cipher[strcspn(cipher, "\n")] = '\0';
        decrypt(cipher, plain, a, b);
        printf("Decrypted plaintext: %s\n", plain);
    }
    return 0;
}
