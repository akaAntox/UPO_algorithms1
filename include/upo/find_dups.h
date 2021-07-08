#ifndef __FIND_DUPS__H__
#define __FIND_DUPS__H__

#include <stdlib.h>
#include <strings.h>

typedef struct upo_strings_list_s *upo_strings_list_t;

upo_strings_list_t upo_find_dups(const char **strs, size_t n);

upo_strings_list_t upo_find_idups(const char **strs, size_t n, int ignore_case);


#endif  //!__FIND_DUPS__H__