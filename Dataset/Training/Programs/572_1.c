#include <assert.h>

extern int __VERIFIER_nondet_int(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    if (n <= 0) {
        return 1;
    }
    assume_abort_if_not(n < 1000); // Assume a reasonable upper bound for analysis

    int fib_prev = 0;
    int fib_curr = 1;
    int fib_next;
    int index = 2; // Start from index 2 since we already initialized the first two Fibonacci numbers

    while (index <= n) {
        fib_next = fib_prev + fib_curr;
        fib_prev = fib_curr;
        fib_curr = fib_next;
        index++;
    }

    // Check if the n-th Fibonacci number is even or odd
    __VERIFIER_assert((fib_curr % 2 == 0) || (fib_curr % 2 == 1));

    return 0;
}