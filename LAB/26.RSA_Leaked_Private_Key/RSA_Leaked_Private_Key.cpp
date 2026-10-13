#include <stdio.h>

long long gcd(long long a, long long b) {
    while (b) { long long t = a % b; a = b; b = t; }
    return a;
}

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

long long modInv(long long a, long long m) {
    for (long long x = 1; x < m; x++)
        if ((a * x) % m == 1) return x;
    return -1;
}

int main(void) {
    long long n = 3599;                  /* 59 * 61 */
    long long e1 = 31, d1 = 3031;        /* Leaked key pair */
    long long e2 = 17;                   /* Bob's new public exponent on same n */

    /* Attack: Use e1*d1 - 1 = k * t (where t is odd) to factor n */
    long long k_phi = e1 * d1 - 1;
    long long t = k_phi;
    while (t % 2 == 0) t /= 2;

    long long p = 1, q = 1;
    for (long long a = 2; a < n; a++) {
        long long x = modExp(a, t, n);
        while (x != 1 && x != n - 1) {
            long long prev = x;
            x = (x * x) % n;
            if (x == 1) {
                p = gcd(prev - 1, n);
                q = n / p;
                break;
            }
        }
        if (p > 1 && p < n) break;
    }

    long long phi = (p - 1) * (q - 1);
    long long d2 = modInv(e2, phi);

    printf("RSA Modulus Reuse Vulnerability Analysis\n");
    printf("Leaked Key Pair : e1 = %lld, d1 = %lld (with modulus n = %lld)\n", e1, d1, n);
    printf("Bob's New Public: e2 = %lld (reusing same modulus n = %lld)\n\n", e2, n);
    printf("Attacker uses e1*d1 - 1 = %lld to factor n:\n", k_phi);
    printf("  Recovered primes : p = %lld, q = %lld\n", p, q);
    printf("  Computed phi(n)  : %lld\n", phi);
    printf("  Compromised New Private Key d2 = %lld\n", d2);
    printf("Conclusion: NOT SAFE. Bob must generate a brand-new modulus n = p'*q'.\n");
    return 0;
}
