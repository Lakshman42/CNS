#include <stdio.h>

long long gcd(long long a, long long b) {
    while (b) { long long t = a % b; a = b; b = t; }
    return a;
}

long long extGCD(long long a, long long b, long long *x, long long *y) {
    if (b == 0) { *x = 1; *y = 0; return a; }
    long long x1, y1;
    long long g = extGCD(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return g;
}

int main(void) {
    /* Suppose n = 3599 (59 * 61), e = 31, and a ciphertext block C was formed
       from a plaintext block M = 118 (which shares factor 59 with n).
       Note that gcd(C, n) == gcd(M^e mod n, n) == gcd(M, n) = p! */
    long long n = 3599, e = 31;
    long long M = 118;                   /* 2 * 59 */
    long long p = gcd(M, n);
    long long q = n / p;
    long long phi = (p - 1) * (q - 1);
    long long x, y;
    extGCD(e, phi, &x, &y);
    long long d = (x % phi + phi) % phi;

    printf("RSA Common Factor Attack\n");
    printf("Public Key: (e = %lld, n = %lld)\n", e, n);
    printf("Plaintext block M = %lld shares a common factor with n:\n", M);
    printf("  p = gcd(M, n) = gcd(C, n) = %lld\n", p);
    printf("  q = n / p     = %lld\n", q);
    printf("  phi(n)        = %lld\n", phi);
    printf("  Recovered Private Key d = %lld (breaks ALL blocks!)\n", d);
    return 0;
}
