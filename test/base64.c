#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "base64.h"

#define SIZE 100

int main()
{
    // 1. Encode
    unsigned char dst[SIZE];
    const size_t dstlen = sizeof(dst);
    size_t *writtenlen = malloc(sizeof(size_t));
    const unsigned char *src = "Hello, World!\n";
    const size_t srclen = strlen(src);

    printf("Encoding\n");
    int result = atchops_base64_encode(dst, dstlen, writtenlen, src, srclen);
    printf("Success? (0 True): %d\n", result);

    if (result == 0)
    {

        printf("Source: %s\n", src);
        printf("Source Length: %zu\n", srclen);
        printf("Destination: %s\n", dst);
        printf("Destination Length: %zu\n", dstlen);
        printf("Written Length: %zu\n", *writtenlen);
    }

    // 2. Decode
    unsigned char dst2[SIZE];
    const size_t dstlen2 = sizeof(dst2);
    size_t *writtenlen2 = malloc(sizeof(size_t));
    const unsigned char *src2 = dst;
    const size_t srclen2 = *writtenlen;

    printf("\nDecoding\n");
    int result2 = atchops_base64_decode(dst2, dstlen2, writtenlen2, src2, srclen2);
    printf("Success? (0 True): %d\n", result2);

    if (result2 == 0)
    {

        printf("Source: %s\n", src2);
        printf("Source Length: %zu\n", srclen2);
        printf("Destination: %s\n", dst2);
        printf("Destination Length: %zu\n", dstlen2);
        printf("Written Length: %zu\n", *writtenlen2);
    }

    free(writtenlen);
    free(writtenlen2);

    return 0;
}