/*
Compute Factorial using a Loop and Ensure Constraints
This program calculates the factorial of a non-negative integer n
by iterating through a loop. It uses constraints to ensure that the
program handles input values within a specific range.
*/

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 8, "reach_error"); }
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
    return;
}

int main() {
    int n;
    long long factorial;
    int i;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 12); // Limiting to 12 to avoid overflow

    factorial = 1;
    i = 1;

    while (1) {
        if (!(i <= n)) {
            break;
        }
        factorial = factorial * i;
        i = i + 1;
    }

    // Verify if the factorial calculation is within expected bounds
    __VERIFIER_assert(factorial > 0 && factorial <= 479001600); // 12! = 479001600

    // Print resulting factorial
    printf("Factorial of %d is %lld\n", n, factorial);

    return 0;
}