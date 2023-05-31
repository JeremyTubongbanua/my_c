// #include <stdio.h>
// #include <string.h>
// #include "aes256.h"

// int main()
// {
//     const unsigned char *key = "1DPU9OP3CYvamnVBMwGgL7fm8yB1klAap0Uc5Z9R79g="; // AES 256 Key (encoded in base64)
//     const unsigned char *plaintext = "lemonade++/123! Hello, World!\n";
//     AESResult *result;
    
//     // 1. Encrypt
//     result = atchops_aes256_encrypt(key, plaintext);
//     printf("Result: %s\n", result->res);
//     printf("Result length: %lu\n", result->reslen);

//     // 2. Decrypt
//     result = atchops_aes256_decrypt(key, result->res);
//     printf("Result: %s\n", result->res);
//     printf("Result length: %lu\n", result->reslen);
//     return 0;    
// }
