#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_LEN 100
void encrypt(char *message, int keyMatrix[][3], int keySize) {
    int messageMatrix[MAX_LEN], encryptedMatrix[MAX_LEN];
    int i, j, k, sum;

    // Check if the message length is odd, if so, append a space
    if (strlen(message) % keySize != 0) {
        message[strlen(message)] = ' ';
    }

    printf("Values of the letters : ");
    for (i = 0; i < strlen(message); i++) {
        if (message[i] == ' ') {
            messageMatrix[i] = 23;//adding filler letter 'x'
        } 
        else {
            messageMatrix[i] = message[i] - 'A';
        }
        printf("%d\t", messageMatrix[i]);
    }
    printf("\n");

    printf("Value after mod : ");
    for (i = 0; i < strlen(message); i += keySize) {
        for (j = 0; j < keySize; j++) {
            sum = 0;
            for (k = 0; k < keySize; k++) {
                sum += keyMatrix[k][j] * messageMatrix[i + k];
            }
            encryptedMatrix[i + j] = sum % 26; 
            printf("%d\t", encryptedMatrix[i+j]);
        }
    }
    printf("\n");

    printf("\nEncrypted message : ");
    for (i = 0; i < strlen(message); i++) {
        if (encryptedMatrix[i] == 26) {
            printf(" ");
        } 
        else {
            printf("%c", encryptedMatrix[i] + 'A');
        }
    }
    printf("\n");
}
int main() {

	int keyMatrix[3][3];
	char message[MAX_LEN];
	int keySize, i, j;


	printf("Enter the size of the key matrix (up to 3): ");
	scanf("%d", &keySize);


	printf("Enter the key matrix:\n");
	for (i = 0; i < keySize; i++) {
		for (j = 0; j < keySize; j++) {
			scanf("%d", &keyMatrix[i][j]);
		}
	}



	printf("Enter the message IN UPPERCASE : ");
	//fgets(message, sizeof(message), stdin);
	scanf("%s", message);

	if ((strlen(message) > 0) && (message[strlen(message) - 1] == '\n')) {
		message[strlen(message) - 1] = '\0';
	}

	encrypt(message, keyMatrix, keySize);

	return 0;
}
