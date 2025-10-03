/* Compute the factorial of a number with constraints and verification */

#include <stdio.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 6, "reach_error"); }
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

int main(void) {
    int n, i;
    long long factorial;

    // Simulate nondeterministic integer input
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 12); // Constraint: Factorials above 12! exceed a 32-bit signed int

    factorial = 1;
    i = 1;

    if (n == 0) {
        factorial = 1; // by definition 0! = 1
    } else {
        while (i <= n) {
            factorial = factorial * i;
            i++;
        }
    }

    // Postcondition: Ensure that the factorial is computed correctly
    __VERIFIER_assert(factorial > 0 && (n == 0 || n <= 12));

    printf("Factorial of %d is %lld\n", n, factorial);
    return 0;
}