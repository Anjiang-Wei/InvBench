#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example-new.c", 5, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n, sum;
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(n >= 0 && n <= 20); // Restrict `n` for safe computation

    sum = 0;
    for (int i = 0; i < n; i++) {
        int f = fib(i);
        sum += f;
    }

    // The assertion here checks that the sum is non-negative
    // There should be no underflow in the computation of Fibonacci numbers within these constraints
    __VERIFIER_assert(sum >= 0);

    printf("Sum of first %d Fibonacci numbers: %d\n", n, sum);

    return 0;
}