#ifndef ADVANCED_POINTERS_H
#define ADVANCED_POINTERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief Print first n bytes of p in hexadecimal
 *
 * \param stream Output stream.
 * \param p Pointer to the memory area
 * \param n Number of bytes of the memory area to be printed.
 */
void upo_hex_fprintf(FILE *stream, const void *p, size_t n);

/**
 * \brief Set first n bytes of p to the value c
 *
 * \param p Pointer to the memory area
 * \param c Value used to set p bytes
 * \param n Number of bytes of the memory area to be set to c.
 */
void upo_mem_set(void *p, unsigned char c, size_t n);

int upo_mem_cmp(const void *p1, const void *p2, size_t n);

int upo_all_of(const void *base, size_t n, size_t sz, int (*pred)(const void *));

#endif /* UPO_HASHTABLE_PRIVATE_H */