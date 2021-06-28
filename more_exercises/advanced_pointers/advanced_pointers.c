#include "advanced_pointers.h"

void upo_hex_fprintf(FILE *stream, const void *p, size_t n)
{
    for (size_t i = 0; i < n; i++)
        fprintf(stream, "0x%lX\t", *(unsigned char *)p + i);
    fprintf(stream, "\n");
}

void upo_mem_set(void *p, unsigned char c, size_t n)
{
    unsigned char *array = p;

    for (size_t i = 0; i < n; i++)
        *(array + i) = c;
}

int upo_mem_cmp(const void *p1, const void *p2, size_t n)
{
    const unsigned char *mem1 = p1, *mem2 = p2;
    int ret = 0;

    for (size_t i = 0; i < n; i++)
        if (mem1 + i > mem2 + i)
            ret = -1;
        else if (mem1 + i < mem2 + i)
            ret = 1;

    return ret;
}

int upo_all_of(const void *base, size_t n, size_t sz, int (*pred)(const void *))
{
    const unsigned char *mem = base;
    int ret = 1;

    for (size_t i = 0; i < n; i++)
        ret = pred(mem + i * sz);

    return ret;
}