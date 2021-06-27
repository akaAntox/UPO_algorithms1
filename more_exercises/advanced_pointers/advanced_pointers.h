#ifndef ADVANCED_POINTERS_H
#define ADVANCED_POINTERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief Print first n bytes of the memory area pointed by p in hexadecimal
 *
 * \param stream Output stream.
 * \param p Pointer to the memory area
 * \param n Number of bytes of the memory area to be printed.
 */
void upo_hex_fprintf(FILE *stream, const void *p, size_t n);

#endif /* UPO_HASHTABLE_PRIVATE_H */