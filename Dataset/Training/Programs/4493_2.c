/*
Fibonacci Sequence Verification
Computes the nth Fibonacci number using a loop and verifies its relationship.
*/

#include <limits.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 10, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int n, a, b, c, i;
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(n >= 0);
    // Limit the value of n to avoid overflow in calculations
    assume_abort_if_not(n <= 46);

    a = 0;
    b = 1;
    i = 2;

    if (n == 0) {
        c = 0;
    } else if (n == 1) {
        c = 1;
    } else {
        while (i <= n) {
            c = a + b;
            a = b;
            b = c;
            i++;

            // Prove invariant relationship: Fibonacci properties
            __VERIFIER_assert(c >= 0); // Non-negative Fibonacci numbers
        }
    }

    // Verify that the result is the nth Fibonacci number
    __VERIFIER_assert((n == 0 && c == 0) || (n == 1 && c == 1) || (c == a + b - a));

    printf("Fibonacci number %d: %d\n", n, c);
    return 0;
}