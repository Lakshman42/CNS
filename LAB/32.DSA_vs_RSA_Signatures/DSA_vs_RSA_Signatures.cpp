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

long long modInv(long long a, long long m) {
    a = ((a % m) + m) % m;
    for (long long x = 1; x < m; x++)
        if ((a * x) % m == 1) return x;
    return -1;
}

void dsaSign(long long hm, long long p, long long q, long long g, long long x, long long k, long long *r, long long *s) {
    *r = modExp(g, k, p) % q;
    *s = (modInv(k, q) * (hm + x * (*r))) % q;
}

int main(void) {
    long long p = 283, q = 47, g = 60, x = 24;   /* DSA domain parameters & private key */
    long long hm = 19;                           /* Message hash H(M) */

    long long r1, s1, r2, s2;
    dsaSign(hm, p, q, g, x, 15, &r1, &s1);       /* Sign #1 with nonce k = 15 */
    dsaSign(hm, p, q, g, x, 31, &r2, &s2);       /* Sign #2 of SAME message with k = 31 */

    long long rsaN = 3599, rsaD = 3031;
    long long rsaSig1 = modExp(hm, rsaD, rsaN);
    long long rsaSig2 = modExp(hm, rsaD, rsaN);

    printf("DSA vs RSA Digital Signature Comparison (Same Message H(M) = %lld)\n", hm);
    printf("DSA Signature 1 (k = 15) : (r = %lld, s = %lld)\n", r1, s1);
    printf("DSA Signature 2 (k = 31) : (r = %lld, s = %lld)  <-- DIFFERENT!\n\n", r2, s2);
    printf("RSA Signature 1          : %lld\n", rsaSig1);
    printf("RSA Signature 2          : %lld                  <-- IDENTICAL!\n\n", rsaSig2);
    printf("Implication: DSA requires a fresh CSPRNG nonce k per signature; if k is ever\n");
    printf("reused on two messages, the attacker solves for private key x immediately!\n");
    return 0;
}
