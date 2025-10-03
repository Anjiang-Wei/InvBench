/*
  Calculates Fibonacci numbers iteratively with constraints
  This program is designed to be analyzed and verified by automated verification tools.
*/

#include <stdbool.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 5, "reach_error"); }
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
    int n, fib1, fib2, fib3;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 30); // Constraint: Only consider up to the 30th Fibonacci number

    fib1 = 0;
    fib2 = 1;
    fib3 = 0;

    for (int i = 2; i <= n; i++) {
        fib3 = fib1 + fib2;

        // Verification Logic: Ensures Fibonacci properties hold
        __VERIFIER_assert(fib3 >= fib2); // Each Fibonacci number must be at least the previous number
        __VERIFIER_assert(fib3 >= fib1); // Each Fibonacci number must be at least the one before the previous number

        fib1 = fib2;
        fib2 = fib3;
    }

    // After the loop, fib3 should hold the nth Fibonacci value
    printf("Fibonacci number %d is %d\n", n, fib3);

    return 0;
}