#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26
//Alphabets: "abcdefghijklmnopqrstuvwxyz"
char generate_cipher(char key[], char cipher[], char decipher[]) {
    bool used[ALPHABET_SIZE] = {false};
    int key_len = strlen(key);
    
    // Create encryption mapping based on the key
    int i,index;
    // Process key letters
    index = 0;
    for (i = 0; i < key_len; i++) {
        if (key[i] >= 'a' && key[i] <= 'z' && !used[key[i] - 'a']) {
            cipher[index] = key[i];
            used[key[i] - 'a'] = true;
            index++;
        }
    }
    
    // Process remaining letters
    for (i = 0; i < ALPHABET_SIZE; i++) {
        if (!used[i]) {
            cipher[index] = 'a' + i;
            index++;
        }
    }
    cipher[index] = '\0';
    
    // Create decryption mapping
    for (i = 0; i < ALPHABET_SIZE; i++) {
        decipher[cipher[i] - 'a'] = 'a' + i;
    }
    decipher[ALPHABET_SIZE] = '\0';
    
    return 0;
}

char monocipher_encr(char a, char cipher[]) {
    if (a >= 'a' && a <= 'z') {
        return cipher[a - 'a'];
    }
    return a; // Return the character as-is if not in range
}

char monocipher_dencr(char a, char decipher[]) {
    if (a >= 'a' && a <= 'z') {
        return decipher[a - 'a'];
    }
    return a; // Return the character as-is if not in range
}

int main() {
    char str[100], str2[100], str3[100],key[100];
    char cipher[ALPHABET_SIZE], decipher[ALPHABET_SIZE];
    
    printf("\nEnter String: ");
    scanf("%s", str);
    
    printf("\nEnter Key: ");
    scanf("%s", key);
    
    generate_cipher(key, cipher, decipher);
    
    printf("\nCipher: %s\n", cipher);
    printf("Decipher: %s\n", decipher);
    
    
    
    int i;
    for (i = 0; str[i]; i++) {
        str2[i] = monocipher_encr(str[i], cipher);
    }
    str2[i] = '\0';
    
    for (i = 0; str2[i]; i++) {
        str3[i] = monocipher_dencr(str2[i], decipher);
    }
    str3[i] = '\0';
    
    printf("\nAfter Encryption: %s\n", str2);
    printf("\nAfter Decryption: %s\n", str3);
    
    return 0;
}
