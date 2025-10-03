// Computation of Factorial with Constraints Verification

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 5, "reach_error"); }
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

int factorial(int n) {
    int res = 1;
    for (int i = 2; i <= n; i++) {
        res *= i;
        __VERIFIER_assert(res > 0); // Ensure no overflow occurs in this limited range
    }
    return res;
}

int main() {
    int n;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10);

    int result = factorial(n);

    // Constraints verification

    // Ensure no integer overflow occurred for factorial computations (valid only due to our bounded input, 0 to 10)
    return 0;
}