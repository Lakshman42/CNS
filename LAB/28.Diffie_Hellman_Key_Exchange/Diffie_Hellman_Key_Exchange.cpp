#include <stdio.h>

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
    long long q = 353, a = 3;            /* Public prime q and primitive root a */
    long long xA = 97, xB = 233;         /* Secret keys of Alice and Bob */

    /* Standard Diffie-Hellman: Y = a^x mod q */
    long long YA = modExp(a, xA, q);
    long long YB = modExp(a, xB, q);
    long long KA = modExp(YB, xA, q);
    long long KB = modExp(YA, xB, q);

    printf("Standard Diffie-Hellman Protocol (q = %lld, a = %lld)\n", q, a);
    printf("  Alice sends Y_A = a^xA mod q = %lld\n", YA);
    printf("  Bob   sends Y_B = a^xB mod q = %lld\n", YB);
    printf("  Shared Secret Key K = %lld (matches: %lld)\n\n", KA, KB);

    /* Flawed Variant: Participants send x^a mod q instead of a^x mod q */
    long long FA = modExp(xA, a, q);
    long long FB = modExp(xB, a, q);
    printf("Flawed Variant (sending x^a mod q instead of a^x mod q):\n");
    printf("  Alice sends xA^a mod q = %lld, Bob sends xB^a mod q = %lld\n", FA, FB);
    printf("  Why it fails: Eve knows 'a' and 'q', so she computes a^-1 mod (q-1)\n");
    printf("  and extracts xA = (xA^a)^(a^-1) mod q directly!\n");
    return 0;
}
