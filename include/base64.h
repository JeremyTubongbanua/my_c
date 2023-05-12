#pragma once

#include <stddef.h>

/**
 * @brief Encodes a string to base64
 * 
 * @param destination the result
 * @param destination_len the size of the result
 * @param written_len the length of the result
 * @param src the string to encode
 * @param src_len the size of the string to encode
 * @return int `0,` if successful
 */
int atchops_base64_encode(unsigned char *dst, size_t dstlen, size_t *writtenlen, const unsigned char *src, const size_t srclen);