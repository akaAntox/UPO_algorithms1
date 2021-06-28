#include <assert.h>
#include <upo/queue.h>

int main()
{
    upo_queue_t queue;
    int v1 = 5, v2 = 7, v3 = 11;

    queue = upo_queue_create();
    assert(queue != NULL);
    assert(upo_queue_size(queue) == 0);
    printf("[OK] Test create: Success!\n");

    upo_queue_enqueue(queue, &v1);
    assert(upo_queue_size(queue) == 1);
    assert(*(int *)upo_queue_peek(queue) == v1);

    upo_queue_dequeue(queue, 0);
    assert(upo_queue_size(queue) == 0);
    assert(upo_queue_is_empty(queue) == 1);
    printf("[OK] Test enqueue/dequeue/size/isempty: Success!\n");

    upo_queue_enqueue(queue, &v1);
    upo_queue_enqueue(queue, &v2);
    upo_queue_enqueue(queue, &v3);
    assert(upo_queue_size(queue) == 3);
    assert(upo_queue_is_empty(queue) == 0);
    assert(*(int *)upo_queue_peek(queue) == v1);

    upo_queue_clear(queue, 0);
    assert(upo_queue_is_empty(queue) == 1);
    printf("[OK] Test clear: Success!\n");

    upo_queue_enqueue(queue, &v1);
    upo_queue_enqueue(queue, &v2);

    upo_queue_destroy(queue, 0);
    assert(upo_queue_is_empty(queue) == 1);
    printf("[OK] Test destroy: Success!\n");
}