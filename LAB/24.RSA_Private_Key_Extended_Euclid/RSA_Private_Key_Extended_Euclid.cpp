#include <stdio.h>

/* Extended Euclidean Algorithm: returns gcd(a, b) and sets *x, *y such that a*x + b*y = gcd */
int extGCD(int a, int b, int *x, int *y) {
    if (b == 0) { *x = 1; *y = 0; return a; }
    int x1, y1;
    int g = extGCD(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return g;
}

int modExp(int base, int exp, int mod) {
    long long res = 1, b = base % mod;
    while (exp > 0) {
        if (exp & 1) res = (res * b) % mod;
        b = (b * b) % mod;
        exp >>= 1;
    }
    return (int)res;
}

int main(void) {
    int e = 31, n = 3599;
    int p = 0, q = 0;

    /* Step 1: Trial-and-error factorization of n = 3599 */
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) { p = i; q = n / i; break; }
    }

    int phi = (p - 1) * (q - 1);
    int x, y;
    extGCD(e, phi, &x, &y);
    int d = (x % phi + phi) % phi;

    printf("RSA Private Key Recovery (e = %d, n = %d)\n", e, n);
    printf("1. Trial-and-error prime factors : p = %d, q = %d (since %d * %d = %d)\n", p, q, p, q, n);
    printf("2. Euler's totient phi(n)        : (%d - 1)*(%d - 1) = %d\n", p, q, phi);
    printf("3. Extended Euclidean Inverse d  : 31^-1 mod %d = %d\n", phi, d);
    printf("   Check: (e * d) mod phi(n)     = (%d * %d) mod %d = %d\n\n", e, d, phi, (e * d) % phi);

    int msg = 1234;
    int enc = modExp(msg, e, n);
    int dec = modExp(enc, d, n);
    printf("Verification: M = %d -> C = M^e mod n = %d -> M' = C^d mod n = %d\n", msg, enc, dec);
    return 0;
}
