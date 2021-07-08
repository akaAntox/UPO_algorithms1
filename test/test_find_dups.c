#include <assert.h>
#include <upo/find_dups.h>

int main()
{
    char **arr1 = {"Tre", "tigri", "contro", "tre", "tigri"};
    upo_strings_list_t str_list = NULL;

    str_list = upo_find_dups(arr1, sizeof(arr1));
    assert(str_list);
    printf("[OK] Test dups: Success!\n");
}