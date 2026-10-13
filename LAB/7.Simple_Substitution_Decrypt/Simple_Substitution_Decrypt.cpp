#include <stdio.h>
#include <string.h>

/* Substitution table deduced from frequency analysis:
   '+' stands for '‡', '!' for '†', '@' for '¶', '-' for '—' */
char decodeChar(char c) {
    switch (c) {
        case '8': return 'E';
        case ';': return 'T';
        case '4': return 'H';
        case '+': return 'O';
        case ')': return 'S';
        case '*': return 'N';
        case '5': return 'A';
        case '6': return 'I';
        case '(': return 'R';
        case '!': return 'D';
        case '1': return 'F';
        case '0': return 'L';
        case '9': return 'M';
        case '2': return 'B';
        case '3': return 'G';
        case ':': return 'Y';
        case '?': return 'U';
        case '.': return 'P';
        case '@': return 'V';
        case ']': return 'W';
        case '-': return 'C';
        default : return c;
    }
}

int main(void) {
    /* Ciphertext with ASCII equivalents for special symbols:
       + = ‡, ! = †, @ = ¶, - = — */
    const char *cipher =
        "53++!305))6*;4826)4+.)4+);806*;48!8@60))85;;]8*;:!*8!83"
        "(88)5*!;46(;88*96*?;8)*+(;485);5*!2:*+(;4956*2(5*-4)8@8*"
        ";4069285);)6!8)4++;1(+9;48081;8:8+1;48!85;4)485!528806*81"
        "(+9;48;(88;4(+?34;48)4+;161;:188;+?;";

    char plain[512];
    int i;
    for (i = 0; cipher[i]; i++)
        plain[i] = decodeChar(cipher[i]);
    plain[i] = '\0';

    printf("Ciphertext:\n%s\n\n", cipher);
    printf("Step 1: '8' appears 33 times (most frequent) -> maps to 'E'\n");
    printf("Step 2: ';48' appears 7 times -> maps to 'THE' (';' = T, '4' = H, '8' = E)\n\n");
    printf("Decrypted Message:\n%s\n", plain);
    return 0;
}
