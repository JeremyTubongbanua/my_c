#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aes256.h"
#include "base64.h"

#define AES_KEY_BITS 256
#define IV_SIZE 16

AESResult *atchops_aes256_encrypt(const char *key_base64, const unsigned char *plaintext)
{
    size_t len = strlen(plaintext);
    // pad the plain text to be a multiple of 16 bytes
    // printf("Padding...\n");
    unsigned char *plaintext_padded;
    size_t plaintext_paddedlen;

    const short int mod = len % 16;
    const short int num_pad_bytes_to_add = 16 - mod;
    const unsigned char padding_val = num_pad_bytes_to_add;

    plaintext_paddedlen = len + num_pad_bytes_to_add;
    // printf("plaintext_paddedlen: %lu = %d + %d\n", plaintext_paddedlen, len, num_pad_bytes_to_add);
    plaintext_padded = malloc(sizeof(unsigned char) * (plaintext_paddedlen+1));
    for(int i = 0; i < len; i++)
    {
        // printf("ia: %d\n", i);
        *(plaintext_padded + i) = *(plaintext + i);
    }
    for(int i = len; i < len + num_pad_bytes_to_add; i++)
    {
        *(plaintext_padded + i) = padding_val;
        // printf("ib: %d\n", i);
    }

    // printf("Plaintext Padded: \"%s\"\n", plaintext_padded);

    // initialize AES key
    unsigned char key[32];
    size_t keylen = sizeof(key);
    size_t *writtenlen = malloc(sizeof(size_t));

    atchops_base64_decode(key, keylen, writtenlen, key_base64, strlen(key_base64));

    // initialize AES context
    mbedtls_aes_context *ctx = malloc(sizeof(mbedtls_aes_context));
    mbedtls_aes_init(ctx);
    mbedtls_aes_setkey_enc(ctx, key, AES_KEY_BITS);

    size_t *iv_ctr = malloc(sizeof(unsigned int));
    unsigned char *iv = malloc(sizeof(unsigned char) * IV_SIZE);
    unsigned char *stream_block = malloc(sizeof(unsigned char) * IV_SIZE);

    unsigned char *aes_encrypted = malloc(sizeof(unsigned char) * 2048);

    // run encrypt
    mbedtls_aes_crypt_ctr(ctx, plaintext_paddedlen, iv_ctr, iv, stream_block, plaintext_padded, aes_encrypted);

    // find how much of the encrypted data is actually used
    int aes_encryptedlen = 0;
    unsigned char byte;
    do {
        byte = *(aes_encrypted + aes_encryptedlen++);
        // printf("%x\n", byte);
    } while(byte != 0);
    --aes_encryptedlen;

    // encode the encrypted data in base64
    size_t dstlen = 2048;
    unsigned char *dst = malloc(sizeof(unsigned char) * dstlen);
    atchops_base64_encode(dst, dstlen, writtenlen, aes_encrypted, aes_encryptedlen);

    // printf("%s\n", dst);

    // done
    AESResult *aes_result = malloc(sizeof(AESResult));
    aes_result->res = dst;
    aes_result->reslen = *writtenlen;

    mbedtls_aes_free(ctx);    
    free(iv_ctr);
    free(iv);
    free(stream_block);
    free(aes_encrypted);

    return aes_result;
}

AESResult *atchops_aes256_decrypt(const char *key, const unsigned char *plaintext)
{
    AESResult *result = malloc(sizeof(AESResult));
    return result;
}