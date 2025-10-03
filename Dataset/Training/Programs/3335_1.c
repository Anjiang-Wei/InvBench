#include <assert.h>
#include <stdio.h>

extern void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
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

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n, m;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10);

    int result = 0;
    int sum_even_fibs = 0;

    for (m = 0; m <= n; m++) {
        result = fibonacci(m);

        // Check if the result is even
        if (result % 2 == 0) {
            sum_even_fibs += result;
        }

        __VERIFIER_assert(result >= 0); // Fib numbers are non-negative
    }

    printf("Sum of even Fibonacci numbers up to fibonacci(%d): %d\n", n, sum_even_fibs);
    return 0;
}