#include <stdio.h>
#include <math.h>

int main(void) {
    double fact25 = 1.0;
    double log2_25 = 0.0;

    for (int i = 1; i <= 25; i++) {
        fact25 *= i;
        log2_25 += log2((double)i);
    }

    /* 25 equivalent grids per key (5 cyclic row rotations x 5 cyclic column rotations) */
    double fact24 = fact25 / 25.0;
    double log2_24 = log2_25 - log2(25.0);

    printf("Playfair Cipher Key Space Analysis\n");
    printf("----------------------------------\n");
    printf("1. Total possible 5x5 matrices (25!):\n");
    printf("   25! = %.6e\n", fact25);
    printf("   log2(25!) = %.2f -> approx 2^%.0f possible keys\n\n", log2_25, round(log2_25));

    printf("2. (a) Effectively unique keys (accounting for 5 row shifts x 5 col shifts = 25 equivalent grids):\n");
    printf("   25! / 25 = 24! = %.6e\n", fact24);
    printf("   log2(24!) = %.2f -> approx 2^%.0f effectively unique keys\n", log2_24, round(log2_24));

    return 0;
}
