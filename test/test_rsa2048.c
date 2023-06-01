#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <mbedtls/rsa.h>
#include "base64.h"
#include <mbedtls/asn1.h>

void printx(unsigned char *data, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        printf("%02x ", data[i]);
    }
    printf("\n");
}

int main()
{
    char *publickey = "MIIEvQIBADANBgkqhkiG9w0BAQEFAASCBKcwggSjAgEAAoIBAQC56T4Cy+K8wuC4pfLUdYRXbPEr+gaGwus+lG6d4jnLDtgjjMLLgZZdYd/eTfGnyF+HLiQk8Cfq+e2C7HSppDLJqTFd2u+CGbLdcN07UR92z/PaJDrwfrqSDgg5A8bmuT+jft8j5iFPq6mGUVMtlcGS045MQRaK8D7WyWHu+CaHMVcrUnt7JrOSaP+vqzoSDiinivJEs4nzF80aU/6i4HHNlVaKOXh6XbXmkCwuHoiVdZw0R7m0luUZ4jcquFQgYkTo1oRdyKLimWHR8nxanZ751pK2OcLsXYznObTFrNFZuRjC7ZTMyLZ8WSVxmu+Q5K0H8XCy7ir35NQX+gO1Vj2fAgMBAAECggEAcaXq2YzHw7qh417W7hgU2djoKYkDelgntK7KXEvSJpahfEHtRrimMdnGH8CoLHgqJZoIUGhbDqLQFcv0mUueHHcIjaZr6a1KEWKQa1VxFZGUMVMakK/335ciYbA0ZBD0nT7Oq8RfsrNuw4Rtg51boyUehPD5FeA9mdGrw4kBDH0Jsu/B6sIDq61lDQCRtpgNS1+qIqrNG8bA7RdXxj0Kxi1BkkXbRvNcFXyxRSDqeA6cljmY+woeLes3gX5ywtD/E3McUWSOF+YkeKrPmdsltSekol0JS0Za7fMmDqQ+emw0Z6iXrMXKX0outSxL44LDBSoNpfpBMSm2Tyh8nkxeGQKBgQD0E3izzoSeTUOotDKKpfTI0Lw/mE7Pc2/86s2iOxZSIBO2T/nQrZOjhN4EltMNhduYtMtkfwzjAlTpvRCs4GPE4VR3lrS1hp8ByNa5/iK7WrPCPQc4poG1zX+SCBovd+2szPkPRH9ZyuVD/NNmFL4jcYsE2OS2h5miZT1ZWrUNQwKBgQDC/lUwkxsUhkJGb6zCNsoVFj84sZ1Mz8yJwBht6qGMLW7DsDRCOg2c+vW/uulB1th/Kdi5PvNqR5hpbk6VFozx/A5ZTOClFG9PAFBneRH5v3+v4NnF+Nl34C9qopEmLMuaC70MZwSA0kSQL8stzatPfz+2VsgpUN5e2a21QbI6dQKBgQDZwrGTArMxpU+zKapaJzyhGhKKTrIpxh1pMnhqwHrmpLXRl8MTmnm5j2aiA4qjawUEVnGM5QmzU7Y8oDFLfBunYT6CP9RUjJo69lwVrxZ/v6nXp6lUssHRWVnzCQWLyl0kKfAf3gYdL7ejE+PsFJ+bcccNeRF9hLfeuqKkoRgdjwKBgHtJzdlJmbyvauYYI/YkKD+O8mhJPPjdBikukQOmb4AvFbKbDV+2TvcrYghZCLS9P+OfNM1jtQpEvGQk/4CaYoF56iSiTAN0WTBtNWlHDouHfhdZJrhasD1wPOrCYN3vQshilaRq2lkNGZbE8UVDngZEoacLVcFxxTfZkFBjemolAoGAAZO1u85l/3bLtHMyOsw6ZmAFvZ0p7D9NoHK/+BZVx3uPpraNldZoJvBQjNZJ+0jpE5ILRPO+T2decyH+v1I8Z7HANcQbqJaAmvAu5+y7XdcFJJksQiQhOd2bh9Eo52pOeKRnd8oYCcoTFo7dAGefCuFqOU6ymDGBJilT2T3NtgI=";
    size_t publickeylen = strlen(publickey);

    // printf("Public Key: %s\n", publickey);

    size_t dstlen = 5000;
    char *dst = malloc(sizeof(unsigned char) * dstlen);
    size_t *writtenlen = malloc(sizeof(size_t) * 1);
    atchops_base64_decode(dst, dstlen, writtenlen, publickey, publickeylen);

    printf("\n");
    printx(dst, *writtenlen);
    printf("writtenlen: %lu\n", *writtenlen);
    printf("\n");

    char *end = dst + (*writtenlen);

    int ret;

    printf("1st get tag\n");
    size_t *lengthread = malloc(sizeof(size_t));
    ret = mbedtls_asn1_get_tag(&dst, end, lengthread, MBEDTLS_ASN1_CONSTRUCTED | MBEDTLS_ASN1_SEQUENCE);
    printf("ret: %d\n", ret);
    printf("lengthread: %lu\n", *lengthread);
    printf("*(dst+0) now points to : %02x\n", *(dst+0));
    printf("*(dst+1) now points to : %02x\n", *(dst+1));
    printf("*(dst+2) now points to : %02x\n", *(dst+2));
    printf("*(dst+3) now points to : %02x\n", *(dst+3));
    printf("*(dst+4) now points to : %02x\n", *(dst+4));

    printf("2nd get tag\n");
    size_t *lengthread2 = malloc(sizeof(size_t));
    ret = mbedtls_asn1_get_tag(&dst, end, lengthread2, MBEDTLS_ASN1_INTEGER);
    printf("ret: %d\n", ret);
    printf("lengthread2: %lu\n", *lengthread2);
    dst = dst + (*lengthread2);
    printf("*(dst+0) now points to : %02x\n", *(dst+0));
    printf("*(dst+1) now points to : %02x\n", *(dst+1));
    printf("*(dst+2) now points to : %02x\n", *(dst+2));
    printf("*(dst+3) now points to : %02x\n", *(dst+3));
    printf("*(dst+4) now points to : %02x\n", *(dst+4));

    printf("3rd get tag\n");
    size_t *lengthread3 = malloc(sizeof(size_t));
    ret = mbedtls_asn1_get_tag(&dst, end, lengthread3, MBEDTLS_ASN1_CONSTRUCTED | MBEDTLS_ASN1_SEQUENCE);
    printf("ret: %d\n", ret);
    printf("lengthread3: %lu\n", *lengthread3);
    dst = dst + (*lengthread3);
    printf("*(dst+0) now points to : %02x\n", *(dst+0));
    printf("*(dst+1) now points to : %02x\n", *(dst+1));
    printf("*(dst+2) now points to : %02x\n", *(dst+2));
    printf("*(dst+3) now points to : %02x\n", *(dst+3));
    printf("*(dst+4) now points to : %02x\n", *(dst+4));

    printf("4th get tag\n");
    size_t *lengthread4 = malloc(sizeof(size_t));
    ret = mbedtls_asn1_get_tag(&dst, end, lengthread4, 0x04);
    printf("ret: %d\n", ret);
    printf("lengthread4: %lu\n", *lengthread4);
    printf("*(dst+0) now points to : %02x\n", *(dst+0));
    printf("*(dst+1) now points to : %02x\n", *(dst+1));
    printf("*(dst+2) now points to : %02x\n", *(dst+2));
    printf("*(dst+3) now points to : %02x\n", *(dst+3));

    printf("5th get tag\n");
    mbedtls_asn1_sequence *seq = malloc(sizeof(mbedtls_asn1_sequence));
    ret = mbedtls_asn1_get_sequence_of(&dst, end, seq, MBEDTLS_ASN1_INTEGER);
    printf("ret: %d\n", ret);

    // traverse seq
    mbedtls_asn1_sequence *current = seq;
    while (current != NULL)
    {
        printf("current->buf.tag: %02x\n", current->buf.tag);
        printf("current->buf.len: %lu\n", current->buf.len);
        printf("current->buf.p:\n");
        for(int i = 0; i < current->buf.len; i++)
        {
            printf("%02x ", *(current->buf.p + i));
        }
        printf("\n");
        current = current->next;
    }
    


    // mbedtls_asn1_sequence *seq = malloc(sizeof(mbedtls_asn1_sequence));
    // ret = mbedtls_asn1_get_sequence_of(&dst, end, seq, MBEDTLS_ASN1_CONSTRUCTED | MBEDTLS_ASN1_SEQUENCE);
    // printf("ret: %d\n", ret);
    
    
    return 0;
}