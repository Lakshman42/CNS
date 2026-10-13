#include <stdio.h>

int gcd(int a, int b) {
    while (b) { int t = a % b; a = b; b = t; }
    return a;
}

int main(void) {
    printf("Affine Caesar Cipher One-to-One Property Verification\n");
    printf("Example of non-invertible key a = 2, b = 3:\n");
    printf("  E([2, 3], 0)  = (2*0 + 3) mod 26  = %d\n", (2 * 0 + 3) % 26);
    printf("  E([2, 3], 13) = (2*13 + 3) mod 26 = %d  (Collision!)\n\n", (2 * 13 + 3) % 26);

    printf("Allowed values of a in 1..25 (gcd(a, 26) == 1):\n  ");
    for (int a = 1; a <= 25; a++)
        if (gcd(a, 26) == 1) printf("%d ", a);

    printf("\n\nDisallowed values of a in 1..25 (gcd(a, 26) != 1):\n  ");
    for (int a = 1; a <= 25; a++)
        if (gcd(a, 26) != 1) printf("%d ", a);
    printf("\n");
    return 0;
}
