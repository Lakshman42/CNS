#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(const char *plain, char *cipher, int k) {
    int i;
    for (i = 0; plain[i] != '\0'; i++) {
        char ch = plain[i];
        if (isupper(ch))
            cipher[i] = (ch - 'A' + k) % 26 + 'A';
        else if (islower(ch))
            cipher[i] = (ch - 'a' + k) % 26 + 'a';
        else
            cipher[i] = ch;
    }
    cipher[i] = '\0';
}

void decrypt(const char *cipher, char *plain, int k) {
    int i;
    for (i = 0; cipher[i] != '\0'; i++) {
        char ch = cipher[i];
        if (isupper(ch))
            plain[i] = (ch - 'A' - k + 26) % 26 + 'A';
        else if (islower(ch))
            plain[i] = (ch - 'a' - k + 26) % 26 + 'a';
        else
            plain[i] = ch;
    }
    plain[i] = '\0';
}

int main(void) {
    char text[256], result[256];
    int k, choice;

    printf("Caesar Cipher\n");
    printf("1. Encrypt\n2. Decrypt\nEnter choice: ");
    if (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
        printf("Invalid choice.\n");
        return 1;
    }

    printf("Enter key k (1-25): ");
    if (scanf("%d", &k) != 1 || k < 1 || k > 25) {
        printf("Key must be between 1 and 25.\n");
        return 1;
    }

    getchar(); 
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; 
    if (choice == 1) {
        encrypt(text, result, k);
        printf("Encrypted text: %s\n", result);
    } else {
        decrypt(text, result, k);
        printf("Decrypted text: %s\n", result);
    }

    return 0;
}
