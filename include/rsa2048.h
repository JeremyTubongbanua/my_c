#include <ctype.h>

typedef struct {
    unsigned char n[256]; // modulus
    unsigned char e[3]; // public exponent
} RSA2048_PublicKey;

typedef struct {
    unsigned char n[256]; // modulus
    unsigned char e[3]; // public exponent
    unsigned char d[256]; // private exponent
    unsigned char p[128]; // prime 1
    unsigned char q[128]; // prime 2
} RSA2048_PrivateKey;

void populate(char *publicKeyBase64, size_t publicKeyBase64len, RSA2048_PublicKey *publicKey);
