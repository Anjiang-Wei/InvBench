#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 3, "reach_error"); }
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
}

int main() {
    int n;
    long long factorial_result, i;
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(n >= 0 && n <= 12); // Constraint to prevent integer overflow for factorial > 12!

    factorial_result = 1;
    i = 1;

    while (i <= n) {
        factorial_result = factorial_result * i;
        i = i + 1;
    }

    __VERIFIER_assert(factorial_result > 0); // Ensuring the result is always positive for valid inputs

    printf("Factorial of %d is %lld\n", n, factorial_result);

    return 0;
}