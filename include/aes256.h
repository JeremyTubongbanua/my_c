#pragma once

#include <mbedtls/aes.h>
#include <string.h>

#define AES_RESLEN 10000

typedef struct {
    unsigned char *res; // result of the encryption/decryption
    size_t reslen; // length of the result written
} AESResult;

AESResult *atchops_aes256_encrypt(const char *key_base64, const unsigned char *plaintext, size_t len);
AESResult *atchops_aes256_decrypt(const char *key_base64, const unsigned char *plaintext, size_t len);
