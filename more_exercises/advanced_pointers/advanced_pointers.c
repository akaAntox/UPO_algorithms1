#include "advanced_pointers.h"

void upo_hex_fprintf(FILE *stream, const void *p, size_t n)
{
    unsigned char *array = p;

    for (size_t i = 0; i < n; i++)
    {
        fprintf(stream, "%02X ", array + i * n);
    }
}