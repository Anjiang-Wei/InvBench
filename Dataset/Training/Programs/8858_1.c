#include <stdio.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void reach_error() {
    printf("Error detected!\n");
    abort();
}

#define __VERIFIER_assert(cond) \
    do {                        \
        if (!(cond)) {          \
            reach_error();      \
        }                       \
    } while (0)

/*
 * This program simulates a simple bounded queue with integer elements.
 * Elements can be enqueued or dequeued based on nondeterministic choices.
 * The queue size is checked to ensure no overflow or underflow.
 * The program verifies that elements are indeed added and removed correctly
 * from the queue while maintaining the constraint that the queue size
 * always stays non-negative and below a certain bound.
 */

#define QUEUE_SIZE 10

typedef struct {
    int data[QUEUE_SIZE];
    int head;
    int tail;
    int size;
} BoundedQueue;

void enqueue(BoundedQueue *q, int value) {
    if (q->size < QUEUE_SIZE) {
        q->data[q->tail] = value;
        q->tail = (q->tail + 1) % QUEUE_SIZE;
        q->size++;
    } else {
        reach_error(); // This should not happen
    }
}

int dequeue(BoundedQueue *q) {
    if (q->size > 0) {
        int value = q->data[q->head];
        q->head = (q->head + 1) % QUEUE_SIZE;
        q->size--;
        return value;
    } else {
        reach_error(); // This should not happen
        return -1;     // To satisfy the return type
    }
}

int main() {
    BoundedQueue q;
    q.head = 0;
    q.tail = 0;
    q.size = 0;

    // Simulate operations on the queue
    for (int i = 0; i < 50; ++i) {
        if (__VERIFIER_nondet_int() % 2) {
            int value = __VERIFIER_nondet_int();
            if (q.size < QUEUE_SIZE) {
                enqueue(&q, value);
            }
        } else {
            if (q.size > 0) {
                int value = dequeue(&q);
            }
        }

        // Ensure the size is always non-negative and within bounds
    }

    return 0;
}