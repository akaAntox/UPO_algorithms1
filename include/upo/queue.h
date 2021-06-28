#ifndef UPO_QUEUE_T
#define UPO_QUEUE_T

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/** \brief The queue abstract data type. */
typedef struct upo_queue_s *upo_queue_t;

/** \brief Creates a new queue. */
upo_queue_t upo_queue_create();

/** \brief Destroys the given queue. */
void upo_queue_destroy(upo_queue_t queue, int destroy_data);

/** \brief Removes all elements from the given queue. */
void upo_queue_clear(upo_queue_t queue, int destroy_data);

/** \brief Inserts the given element into the given queue. */
void upo_queue_enqueue(upo_queue_t queue, void *data);

/** \brief Removes the next element from the given queue. */
void upo_queue_dequeue(upo_queue_t queue, int destroy_data);

/** \brief Returns the next element from the given queue. */
void *upo_queue_peek(const upo_queue_t queue);

/** \brief Returns the length of the given queue. */
size_t upo_queue_size(const upo_queue_t queue);

/** \brief Tells whether the given queue is empty. */
int upo_queue_is_empty(const upo_queue_t queue);

#endif /* UPO_QUEUE_T */