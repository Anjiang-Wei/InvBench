#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

extern int __VERIFIER_nondet_int(void);

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    int prev = 0, curr = 1, next, i;
    for (i = 2; i <= n; ++i) {
        next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

int main() {
    int n = __VERIFIER_nondet_int();
    if (n < 0 || n > 20) {
        return 0; // Constraints to prevent overflow
    }

    int fib_n = fibonacci(n);

    // We know the Fibonacci series starts with 0, 1, 1, 2, 3, 5...
    // So fib(0) = 0, fib(1) = 1, fib(2) = 1, fib(3) = 2, etc.
    if (n == 0) {
    } else if (n == 1) {
    } else if (n == 2) {
    } else if (n == 3) {
        __VERIFIER_assert(fib_n == 2);
    }

    return 0;
}