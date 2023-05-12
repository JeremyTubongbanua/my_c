// #include <stddef.h>
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include "base64.h"

// #define DSTSIZE 500

// int main()
// {
//     unsigned char dst[DSTSIZE];
//     size_t *dstlen = sizeof(dst);
//     size_t *writtenlen = malloc(sizeof(size_t));
//     const unsigned char *src = "1DPU9OP3CYvamnVBMwGgL7fm8yB1klAap0Uc5Z9R79g=";
//     const size_t srclen = strlen(src);

//     int result = atchops_base64_decode(dst, dstlen, writtenlen, src, srclen);
//     printf("Success? (0 True): %d\n", result);
//     printf("Destination: %s\n", dst);
//     for(int i = 0; i < *writtenlen; i++)
//     {
//         printf("%x ", dst[i]);
//     }
//     printf("\n");
//     printf("Written length: %d\n", *writtenlen);

//     return 0;
// }