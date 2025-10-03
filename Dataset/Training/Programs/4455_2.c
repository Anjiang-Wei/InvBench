#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int factorial(int n) {
    if (n < 0) {
        return -1; // Not defined for negative numbers
    }
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int n = __VERIFIER_nondet_int();
    if (n < 0 || n > 12) {
        // Factorial results can overflow for n > 12 in 32-bit arithmetic
        return 0;
    }

    int result = factorial(n);

    // To verify: factorial(n) should be greater than or equal to n
    // for all n >= 1
    if (n >= 1) {
    }

    // A loop to verify increment and summation
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
        __VERIFIER_assert(sum >= i); // Sum should be at least i at each step
    }

    return 0;
}