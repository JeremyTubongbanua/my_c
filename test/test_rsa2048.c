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

    mbedtls_asn1_sequence *seq = malloc(sizeof(mbedtls_asn1_sequence));

    // int ret = mbedtls_asn1_get_sequence_of(&dst, dst + (*writtenlen), seq, MBEDTLS_ASN1_CONSTRUCTED | MBEDTLS_ASN1_SEQUENCE | 0x30 | 0x02 | 0x04);
    // printf("ret: %d\n", ret);

    size_t *lengthread = malloc(sizeof(size_t));
    int ret = mbedtls_asn1_get_tag(&dst, dst + (*writtenlen), lengthread, MBEDTLS_ASN1_CONSTRUCTED | MBEDTLS_ASN1_SEQUENCE);
    printf("ret: %d\n", ret);
    printf("lengthread: %lu\n", *lengthread);
    printf("*(dst+0) now poitns to : %02x\n", *(dst+0));
    printf("*(dst+1) now poitns to : %02x\n", *(dst+1));
    printf("*(dst+2) now poitns to : %02x\n", *(dst+2));
    printf("*(dst+3) now poitns to : %02x\n", *(dst+3));
    printf("*(dst+4) now poitns to : %02x\n", *(dst+4));

    ret = mbedtls_asn1_get_tag(&dst, dst + (*lengthread), lengthread, MBEDTLS_ASN1_CONSTRUCTED | MBEDTLS_ASN1_SEQUENCE);
    printf("ret: %d\n", ret);
    return 0;
}