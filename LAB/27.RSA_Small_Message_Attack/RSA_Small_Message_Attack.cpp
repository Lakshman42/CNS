#include <stdio.h>
#include <string.h>

long long modExp(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

int main(void) {
    long long e = 65537, n = 10403;      /* Public key (e, n) */
    const char *msg = "HELLO";
    long long cipher[5];

    /* Alice encrypts each letter (0..25) separately */
    for (int i = 0; i < 5; i++)
        cipher[i] = modExp(msg[i] - 'A', e, n);

    /* Attacker precomputes lookup table for all 26 possible plaintexts (0..25) */
    long long table[26];
    for (int m = 0; m < 26; m++)
        table[m] = modExp(m, e, n);

    char cracked[6];
    for (int i = 0; i < 5; i++) {
        for (int m = 0; m < 26; m++) {
            if (cipher[i] == table[m]) {
                cracked[i] = 'A' + m;
                break;
            }
        }
    }
    cracked[5] = '\0';

    printf("RSA Character-by-Character (0..25) Encryption Attack\n");
    printf("Alice's Message   : %s\n", msg);
    printf("RSA Cipher Blocks : ");
    for (int i = 0; i < 5; i++) printf("%lld ", cipher[i]);
    printf("\n\nAttacker precomputes m^e mod n for m = 0..25 (only 26 encryptions):\n");
    printf("Cracked Message   : %s\n", cracked);
    printf("Conclusion: Insecure! Always use large blocks with random padding (OAEP).\n");
    return 0;
}
