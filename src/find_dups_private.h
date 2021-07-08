#ifndef __FIND_DUPS_PRIVATE__H__
#define __FIND_DUPS_PRIVATE__H__

#include <upo/find_dups.h>

struct upo_strings_list_node_s
{
    char *string;
    struct upo_strings_list_node_s *next;
};
typedef struct upo_strings_list_node_s upo_strings_list_node_t;

struct upo_strings_list_s
{
    upo_strings_list_node_t *head;
};

#endif //!__FIND_DUPS_PRIVATE__H__