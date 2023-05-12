#include <stdio.h>
#include <string.h>
#include "aes256.h"

int main()
{
    const unsigned char *plaintext = "lemonade";
    const unsigned char *key = "1DPU9OP3CYvamnVBMwGgL7fm8yB1klAap0Uc5Z9R79g="; // AES 256 Key (encoded in base64)
    AESResult *result = atchops_aes256_encrypt(key, plaintext);
    printf("Result: %s\n", result->res);
    printf("Result length: %lu\n", result->reslen);
    return 0;    
}
