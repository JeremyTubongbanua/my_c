#include <stdio.h>
#include <string.h>
#include "base64.h"

#define SIZE 10000

int main()
{
    unsigned char dst[SIZE];
    const size_t dstlen = sizeof(dst);
    size_t *writtenlen;
    unsigned char *src = "Hello, World!\n";
    const size_t srclen = strlen(src);

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
    return 0;
}