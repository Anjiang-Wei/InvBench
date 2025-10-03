#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "gen.c", 5, "reach_error"); }

// Function to simulate non-deterministic integer
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

// Function to compute Fibonacci sequence
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    int fib = 1;
    int prevFib = 0;
    for (int i = 2; i <= n; ++i) {
        int newFib = fib + prevFib;
        prevFib = fib;
        fib = newFib;
    }
    return fib;
}

int main() {
    int m = __VERIFIER_nondet_int();
    assume_abort_if_not(m <= 20); // Limit to avoid overflow for demonstration
    assume_abort_if_not(m >= 0);

    int fib_m = fibonacci(m);

    int sum = 0;
    for (int i = 0; i <= m; ++i) {
        sum += i;
    }

    printf("Fibonacci of %d is %d\n", m, fib_m);
    printf("Sum from 0 to %d is %d\n", m, sum);

    __VERIFIER_assert(sum >= m); // Constraint to check

    return 0;
}