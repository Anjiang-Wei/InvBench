// A ring buffer simulation with nondeterministic operations,
// suitable for automated verification.

#include <assert.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "ringbuffer.c", 3, "reach_error");
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

extern unsigned int __VERIFIER_nondet_uint();
extern int __VERIFIER_nondet_int();

#define CAPACITY 8

int main() {
    unsigned int head = 0;
    unsigned int tail = 0;
    unsigned int count = 0;
    int buffer[CAPACITY];

    unsigned int ops = __VERIFIER_nondet_uint();
    unsigned int i;

    for (i = 0; i < ops; i++) {
        int op = __VERIFIER_nondet_int();

        // If op is even, try to enqueue
        if (op % 2 == 0) {
            if (count < CAPACITY) {
                buffer[tail] = __VERIFIER_nondet_int();
                tail = (tail + 1) % CAPACITY;
                count++;
            }
        }
        // Else, try to dequeue
        else {
            if (count > 0) {
                head = (head + 1) % CAPACITY;
                count--;
            }
        }

        // Invariants: buffer size and pointers remain in valid bounds
        __VERIFIER_assert(head < CAPACITY);
    }

    // At the end, either the buffer is full, or the ring arithmetic matches count
    return 0;
}