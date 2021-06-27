#include <stdio.h>
#include <stdlib.h>
#include "advanced_pointers.h"

int main()
{
    char *s = "Hello, World!";
    upo_hex_fprintf(stdout, s, strlen(s));

    char cary[] = "GNU is Not Unix";
    upo_hex_fprintf(stdout, cary + (sizeof cary) / 2, sizeof cary - (sizeof cary) / 2);

    unsigned char ucary[] = {255, 128, 64, 32, 16};
    upo_hex_fprintf(stderr, ucary, sizeof ucary);

    return 1;
}
