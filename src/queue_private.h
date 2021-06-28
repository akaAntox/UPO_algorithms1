#ifndef __QUEUE_PRIVATE__H__
#define __QUEUE_PRIVATE__H__

#include <stdlib.h>
#include <upo/queue.h>

struct upo_queue_list_s
{
    void *data;
    struct upo_queue_list_s *next;
};

typedef struct upo_queue_list_s *upo_queue_list_t;

struct upo_queue_s
{
    upo_queue_list_t first;
    upo_queue_list_t last;
    size_t size;
};

#endif  //!__QUEUE_PRIVATE__H__