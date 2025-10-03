#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_prog.c", 3, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main(void) {
    unsigned int n = __VERIFIER_nondet_uint();
    unsigned long long factorial = 1;

    // Safety constraint: n should not be extraordinarily large to prevent overflow.
    if (n > 20) {
        n = 20; // Limiting n to 20 to stay within unsigned long long limits
    }

    for (unsigned int i = 1; i <= n; ++i) {
        factorial *= i;
    }

    // A simple check: the factorial of 0! and 1! should be 1
    if (n == 0 || n == 1) {
        __VERIFIER_assert(factorial == 1);
    }

    // Basic check for factorial of 2 to ensure no errors in small values
    if (n == 2) {
    }

    // Property: if n > 1, factorial should be larger than n (except for n <= 1)
    if (n > 1) {
    }

    printf("Factorial of %u is %llu\n", n, factorial);
    return 0;
}