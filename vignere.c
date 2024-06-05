#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void printVigenereTable() {
    printf("Vigenere Table\n");
    printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z \n");
    for(int i = 0; i < 26; i++) {
        printf("%c", 'A' + i);
        for(int j = 0; j < 26; j++) {
            printf("%c", 'A' + (i + j) % 26);
        }
        printf("\n");
    }
}

void encrypt() {
    char plaintext[128];
    char key[16];
    printf("Enter the plain text: ");
    scanf(" %[^\n]", plaintext);
    getchar();
    printf("Enter the key: ");
    scanf(" %[^\n]", key);
    getchar();
    printf("Cipher text is: ");
    for(int i = 0, j = 0; i < strlen(plaintext); i++, j++) {
        if(j >= strlen(key)) {
            j = 0;
        }
        int shift = toupper(key[j]) - 'A';
        char encryptChar = ((toupper(plaintext[i]) - 'A' + shift) % 26) + 'A';
        printf("%c", encryptChar);
    }
    printf("\n");
}

void decrypt() {
    char ciphertext[128];
    char key[16];
    printf("Enter the cipher text: ");
    scanf(" %[^\n]", ciphertext);
    getchar();
    printf("Enter the key: ");
    scanf(" %[^\n]", key);
    getchar();
    printf("Decrypted text: ");
    for(int i = 0, j = 0; i < strlen(ciphertext); i++, j++) {
        if(j >= strlen(key)) {
            j = 0;
        }
        int shift = toupper(key[j]) - 'A';
        char decryptChar = ((toupper(ciphertext[i]) - 'A' - shift + 26) % 26) + 'A';
        printf("%c", decryptChar);
    }
    printf("\n");
}

int main() {
    int option;
    while (1) {
        printf("\n1. Encrypt\n");
        printf("2. Decrypt\n");
        printf("3. Print Vigenère Table\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                encrypt();
                break;
            case 2:
                decrypt();
                break;
            case 3:
                printVigenereTable();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid selection! Try again.\n");
                break;
        }
    }
    return 0;
}
