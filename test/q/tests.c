#include "queue.h"

#include <stdio.h>

struct Pair {
    int a;
    float b;
};

int main() {
    struct Pair one = {1, 1.1};
    struct Pair two = {2, 2.2};

    Queue q;create_queue(&q, sizeof(struct Pair));

    push_to_queue(&q, &one);
    push_to_queue(&q, &two);
    push_to_queue(&q, &two);
    push_to_queue(&q, &one);

    struct Pair p;
    while (pop_from_queue(&q, &p) != -1) {
        printf("%d, %f\n", p.a, p.b);
    }

    destroy_queue(&q);
    return 0;
}
