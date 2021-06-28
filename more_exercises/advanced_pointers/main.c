#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "advanced_pointers.h"

int is_even(const void *v)
{
    assert(v);
    return *((const int *)v) % 2;
}

int is_palindrome(const void *v)
{
    assert(v);
    const char **ps = (const char **)v;
    size_t len = strlen(*ps);
    for (size_t i = 0; i < len / 2; ++i)
    {
        if ((*ps)[i] != (*ps)[len - i - 1])
            return 0;
    }
    return 1;
}

int main()
{
    // EXERCISE 1
    printf("--- Exercise 1 ---\n");

    char *s = "Hello, World!";
    upo_hex_fprintf(stdout, s, strlen(s));

    char cary[] = "GNU is Not Unix";
    upo_hex_fprintf(stdout, cary + (sizeof cary) / 2, sizeof cary - (sizeof cary) / 2);

    unsigned char ucary[] = {255, 128, 64, 32, 16};
    upo_hex_fprintf(stderr, ucary, sizeof ucary);

    // EXERCISE 2
    printf("--- Exercise 2 ---\n");

    char cary_2[] = "Hello, World!";
    upo_mem_set(cary_2, '?', strlen(cary_2));
    printf("%s\n", cary_2);

    int i = 10;
    upo_mem_set(&i, 0, sizeof i);
    printf("%d\n", i);

    unsigned char ucary_2[] = {255, 128, 64, 32, 16, 8};
    upo_mem_set(ucary_2, 127, (sizeof ucary_2) / 2);
    for (i = 0; i < sizeof ucary_2; i++)
        printf("%d ", ucary_2[i]);
    printf("\n");

    // EXERCISE 3
    printf("--- Exercise 3 ---\n");

    // EXERCISE 4
    printf("--- Exercise 4 ---\n");
    int iary[] = {0, 2, 10, 6, 40};
    printf("%d\n", upo_all_of(iary, sizeof iary, sizeof iary / sizeof(int), is_even));

    // char *sary[] = {"acca", "ara", "raar"};
    // printf("%d\n",  upo_all_of(sary, sizeof sary, sizeof sary / sizeof sary[0], is_palindrome));

    return 1;
}
