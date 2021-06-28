#include "queue_private.h"

upo_queue_t upo_queue_create()
{
    upo_queue_t queue = malloc(sizeof(upo_queue_t));
    if (queue == NULL)
    {
        perror("Unable to create a stack");
        abort();
    }

    queue->first = NULL;
    queue->last = NULL;
    queue->size = 0;

    return queue;
}

void upo_queue_destroy(upo_queue_t queue, int destroy_data)
{
    if (queue != NULL)
    {
        upo_queue_clear(queue, destroy_data);
        free(queue);
    }
}

void upo_queue_clear(upo_queue_t queue, int destroy_data)
{
    if (queue == NULL)
        return;

    while (queue->first != NULL)
    {
        upo_queue_list_t tmpPtr = queue->first;
        queue->first = queue->first->next;

        if (destroy_data)
            free(tmpPtr->data);
        free(tmpPtr);
    }
    queue->size = 0;
}

void upo_queue_enqueue(upo_queue_t queue, void *data)
{
    if (queue == NULL)
        return;

    upo_queue_list_t newPtr = malloc(sizeof(upo_queue_list_t));
    if (newPtr == NULL)
    {
        perror("Unable to create a queue node");
        abort();
    }
    newPtr->data = data;
    newPtr->next = NULL;

    if (queue->first == NULL)
        queue->first = newPtr;
    else
        queue->last->next = newPtr;
    queue->last = newPtr;

    queue->size += 1;
}

void upo_queue_dequeue(upo_queue_t queue, int destroy_data)
{
    if (queue == NULL)
        return;

    upo_queue_list_t delPtr = queue->first;
    queue->first = queue->first->next;

    if (destroy_data)
        free(delPtr->data);
    free(delPtr);

    queue->size -= 1;
}

void *upo_queue_peek(const upo_queue_t queue)
{
    if (queue == NULL)
        return 0;

    return queue->first->data;
}

size_t upo_queue_size(const upo_queue_t queue)
{
    if (queue == NULL)
        return 0;

    return queue->size;
}

int upo_queue_is_empty(const upo_queue_t queue)
{
    if (queue == NULL)
        return 0;

    if (queue->size == 0)
        return 1;
    else
        return 0;
}