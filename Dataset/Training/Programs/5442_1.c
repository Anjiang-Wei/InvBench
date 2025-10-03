#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
    return;
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0;
    int b = 1;
    int c;

    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0);
    assume_abort_if_not(n <= 30); // Limit n to prevent overflow and excessive computation

    int fib_result = fibonacci(n);

    /* Check if the result satisfies basic properties of Fibonacci sequence */
    if (n > 1) {
        __VERIFIER_assert(fib_result >= 0); // Fibonacci numbers should be non-negative
    }

    /* Run properties related to Fibonacci on specific conditions */
    if (n == 5) {
        // The 5th Fibonacci number is known to be 5
        __VERIFIER_assert(fib_result == 5);
    }

    if (n == 10) {
        // The 10th Fibonacci number is known to be 55
    }

    return 0;
}