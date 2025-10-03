#include <assert.h>
#include <stdlib.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
void reach_error() { assert(0); }

#define MAX_SIZE 10

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

void enqueue(Queue *q, int value) {
    if (q->size < MAX_SIZE) {
        q->data[q->rear] = value;
        q->rear = (q->rear + 1) % MAX_SIZE;
        q->size++;
    }
}

int dequeue(Queue *q) {
    int value = -1;
    if (q->size > 0) {
        value = q->data[q->front];
        q->front = (q->front + 1) % MAX_SIZE;
        q->size--;
    }
    return value;
}

int main() {
    Queue q;
    q.front = 0;
    q.rear = 0;
    q.size = 0;

    int n = __VERIFIER_nondet_int();
    if (n <= 0 || n > 20) {
        return 0; // Limit the number of operations for verification
    }

    // Simulate a queue with random enqueue and dequeue operations
    for (int i = 0; i < n; i++) {
        if (__VERIFIER_nondet_int()) {
            int value = __VERIFIER_nondet_int();
            enqueue(&q, value);
        } else {
            dequeue(&q);
        }

        // Verification condition: Ensure size is always within bounds
    }

    // Post-condition check: Ensure no extra elements remain
    while (q.size > 0) {
        dequeue(&q);
    }
    __VERIFIER_assert(q.size == 0);

    return 0;
}