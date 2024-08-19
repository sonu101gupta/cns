#include <stdio.h>
#include <ctype.h>

void encrypt(char text[], int key) {
    char ch;
    for (int i = 0; text[i] != '\0'; ++i) {
        ch = text[i];
        if (islower(ch)) {
            ch = (ch - 'a' + key) % 26 + 'a';
        }
        else if (isupper(ch)) {
            ch = (ch - 'A' + key) % 26 + 'A';
        }
        else {
            printf("Invalid Message");
            return;
        }
        text[i] = ch;
    }
}

void decrypt(char text[], int key) {
    char ch;
    for (int i = 0; text[i] != '\0'; ++i) {
        ch = text[i];
        if (islower(ch)) {
            ch = (ch - 'a' - key + 26) % 26 + 'a';
        }
        else if (isupper(ch)) {
            ch = (ch - 'A' - key + 26) % 26 + 'A';
        }
        else {
            printf("Invalid Message");
            return;
        }
        text[i] = ch;
    }
}

int main() {
    char text[500];
    int key;
    printf("Enter a message: ");
    scanf("%s", text);
    printf("Enter the key: ");
    scanf("%d", &key);

    // Encrypting the message
    encrypt(text, key);
    printf("Encrypted message: %s\n", text);

    // Decrypting the message
    decrypt(text, key);
    printf("Decrypted message: %s\n", text);

    return 0;
}
