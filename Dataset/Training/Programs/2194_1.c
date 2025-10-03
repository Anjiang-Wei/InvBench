#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

extern void abort(void);
extern unsigned __VERIFIER_nondet_uint(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    int prev = 0;
    int curr = 1;
    int next = 0;

    for (int i = 2; i <= n; i++) {
        next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

int main() {
    unsigned n = __VERIFIER_nondet_uint();
    assume_abort_if_not(n >= 0 && n < 20); // Limit the range to prevent overflow

    int fib_n = fibonacci(n);

    // Verify that the Fibonacci number is non-negative
    __VERIFIER_assert(fib_n >= 0);

    // Additional property: fib(n) >= fib(n-1) for n >= 1
    if (n >= 1) {
        int fib_n_minus_1 = fibonacci(n - 1);
    }

    return 0;
}