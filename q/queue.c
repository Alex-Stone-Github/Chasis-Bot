#include "./queue.h"

#include <stdlib.h>
#include <string.h>

static void double_queue_capacity(Queue*);

void create_queue(Queue* queue, size_t element_size) {
    Queue q = {
        malloc(element_size),
        element_size,
        0,
        1,
    };
    memcpy(queue, &q, sizeof(Queue));
}
void destroy_queue(Queue* queue) {
    free(queue->base);
}
void push_to_queue(Queue* queue, const void* element) {
    if (!(queue->element_capacity - queue->element_count > 0)) {
        double_queue_capacity(queue);
    }
    void* top = queue->base + queue->element_size*queue->element_count; 
    memcpy(top, element, queue->element_size);
    queue->element_count ++;
}
int pop_from_queue(Queue* queue, void* element) {
    if (!(queue->element_count > 0)) {
        return -1;
    }
    memcpy(element, queue->base, queue->element_size);
    queue->element_count --;
    memmove(queue->base, queue->base+queue->element_size, queue->element_count*queue->element_size);
    return 0;
}
static void double_queue_capacity(Queue* queue) {
    queue->base = realloc(queue->base, (queue->element_size*queue->element_capacity)*2);
    queue->element_capacity *= 2;
}