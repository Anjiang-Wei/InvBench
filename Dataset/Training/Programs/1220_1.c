#include <assert.h>
#include <stdlib.h>
void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);
extern void __VERIFIER_assume(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

// Implementing a simple algorithm to simulate queue behavior using a circular buffer
#define BUFFER_SIZE 256

int main(void) {
    int buffer[BUFFER_SIZE];
    int head = 0;
    int tail = 0;
    int isFull = 0;

    // Given some number of operations
    int operations = __VERIFIER_nondet_int();
    __VERIFIER_assume(operations > 0 && operations <= BUFFER_SIZE);

    while (operations > 0) {
        int operationType = __VERIFIER_nondet_int();
        __VERIFIER_assume(operationType == 0 || operationType == 1);

        if (operationType == 0) { // enqueue
            if (!isFull) {
                buffer[tail] = __VERIFIER_nondet_int();
                tail = (tail + 1) % BUFFER_SIZE;
                if (tail == head) {
                    isFull = 1;
                }
            }
        } else { // dequeue
            if (head != tail || isFull) {
                head = (head + 1) % BUFFER_SIZE;
                isFull = 0;
            }
        }
        operations--;
    }

    // Check properties for the buffer
    int count = (tail >= head) ? (tail - head) : (BUFFER_SIZE + tail - head);
    if (isFull) {
        count = BUFFER_SIZE;
    }

    // Assert that buffer never exceeded its capacity
    __VERIFIER_assert(count <= BUFFER_SIZE);

    return 0;
}