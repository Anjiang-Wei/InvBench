#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 4, "reach_error"); }
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
    int n, m;
    long long factorial_A, factorial_B, counter_A, counter_B;

    // Non-deterministic integers
    n = __VERIFIER_nondet_int();
    m = __VERIFIER_nondet_int();

    // Constraints
    assume_abort_if_not(n >= 0 && n <= 10);
    assume_abort_if_not(m >= 0 && m <= 10);

    // Initialize
    factorial_A = 1;
    factorial_B = 1;
    counter_A = 0;
    counter_B = 0;

    // Calculate the factorial of n
    while (counter_A < n) {
        counter_A++;
        factorial_A *= counter_A;
    }

    // Calculate the factorial of m
    while (counter_B < m) {
        counter_B++;
        factorial_B *= counter_B;
    }

    // Conditions to verify
    __VERIFIER_assert(factorial_B >= 1);

    // Check a property related to both factorials

    return 0;
}