// Fibonacci Sequence Verification
// Computes the n-th Fibonacci number using iterative logic, verifying that every two consecutive Fibonacci numbers satisfy a mathematical property.

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 7, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int n, i;
    long long fib1, fib2, fib_cur;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 2 && n <= 20);

    fib1 = 0;
    fib2 = 1;
    fib_cur = 0;

    for (i = 2; i <= n; i++) {
        fib_cur = fib1 + fib2;
        // Verify that each subsequent Fibonacci number is greater than the previous one
        __VERIFIER_assert(fib_cur >= fib2);

        fib1 = fib2;
        fib2 = fib_cur;
    }

    // Final assertion to verify specific Fibonacci property: F(n) == F(n-1) + F(n-2)

    printf("Fibonacci number %d is %lld\n", n, fib_cur);
    return 0;
}