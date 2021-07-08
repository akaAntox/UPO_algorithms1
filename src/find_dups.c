#include "find_dups_private.h"

/*** BEGIN of MORE EXERCISE ***/

upo_strings_list_t upo_find_dups(const char **strs, size_t n)
{
    upo_strings_list_t list = NULL;

    for (size_t i = 0; i < n; ++i)
        for (size_t k = i + 1; k < n; ++i)
            if (strcmp(strs + i, strs + k) == 0)
            {
                upo_strings_list_node_t *node = malloc(sizeof(upo_strings_list_node_t));
                node->string = strs + i;
                node->next = list;
                list = node;
            }

    return list;
}

upo_strings_list_t upo_find_idups(const char **strs, size_t n, int ignore_case)
{
    upo_strings_list_t list = NULL;

    for (size_t i = 0; i < n; ++i)
        for (size_t k = i + 1; k < n; ++i)
            if (ignore_case ? strcicmp(strs + i, strs + k) == 0 : strcmp(strs + i, strs + k) == 0)
            {
                upo_strings_list_node_t *node = malloc(sizeof(upo_strings_list_node_t));
                node->string = strs + i;
                node->next = list;
                list = node;
            }

    return list;
}

int strcicmp(char const *a, char const *b)
{
    for (;; a++, b++)
    {
        int d = tolower((unsigned char)*a) - tolower((unsigned char)*b);
        if (d != 0 || !*a)
            return d;
    }
}



/*** END of MORE EXERCISE ***/
