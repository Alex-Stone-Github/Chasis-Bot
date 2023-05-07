#ifndef QUEUE
#define QUEUE

#include <stddef.h>

typedef struct Queue {
    void* base;
    size_t element_size;
    size_t element_count;
    size_t element_capacity;
} Queue;

void create_queue(Queue* queue, size_t element_size);
void destroy_queue(Queue* queue);
void push_to_queue(Queue* queue, const void* element);
int pop_from_queue(Queue* queue, void* element);

#endif