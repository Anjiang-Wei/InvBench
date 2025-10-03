/*
Fibonacci Series
Generates Fibonacci numbers and verifies the property of it
*/

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 10, "reach_error"); }
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

int __VERIFIER_nondet_int(void);

int main() {
    int n, i;
    long long fib1 = 0, fib2 = 1, fib_current;

    // Assume nondeterministic values for n
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0); // n should be a non-negative integer

    for (i = 2; i <= n; ++i) {
        fib_current = fib1 + fib2;
        fib2 = fib_current;
    }

    // Verify additional property after the loop
    // If n is greater than or equal to 2, then fib2 should be greater than or equal to 1
    if (n >= 2) {
        __VERIFIER_assert(fib2 >= 1);
    }

    printf("Fibonacci number at position %d is %lld\n", n, fib1);
    return 0;
}