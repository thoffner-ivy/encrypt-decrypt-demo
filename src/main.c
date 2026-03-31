#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LENGTH 16
#define MESSAGE_LENGTH 16

void print_encrypted(const char *message);
void xor_cipher(char *message, const char *key);

int main(void) {
    // Input message
    char message[MESSAGE_LENGTH];

    fputs("Please input a message: ", stdout);

    fgets(message, sizeof message / sizeof *message, stdin);
    message[strcspn(message, "\n")] = '\0';

    // Input key
    char key[KEY_LENGTH];

    fputs("Please input a key: ", stdout);

    fgets(key, sizeof key / sizeof *key, stdin);
    key[strcspn(key, "\n")] = '\0';

    // Encrypt message
    xor_cipher(message, key);

    fputs("Encrypted message: ", stdout);
    print_encrypted(message);
    putchar('\n');

    // Decrypt message
    xor_cipher(message, key);

    printf("Decrypted message: %s\n", message);

    return EXIT_SUCCESS;
}

void print_encrypted(const char *message) {
    size_t message_length = strlen(message);

    for (size_t i = 0; i < message_length; ++i) {
        printf("%02x ", message[i]);
    }
}

void xor_cipher(char *message, const char *key) {
    size_t message_length = strlen(message);
    size_t key_length = strlen(key);

    for (size_t i = 0; i < message_length; ++i) {
        message[i] ^= key[i % key_length];
    }
}
