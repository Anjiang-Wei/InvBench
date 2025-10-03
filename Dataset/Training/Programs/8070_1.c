#include <stdio.h>

// Verification functions
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 6, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int factorial(int n) {
    if (n < 0) {
        return 0; // Edge case: factorial not defined for negative numbers
    }
    int result = 1;
    int i;
    for (i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main(void) {
    int n = __VERIFIER_nondet_int();
    if (n < 0 || n > 12) {
        return 0; // We limit n to prevent integer overflow
    }

    int fact = factorial(n);

    // Verify that factorial(n) is non-negative and within the expected range
    __VERIFIER_assert(fact >= 0 && fact <= 479001600); // 479001600 is 12!

    // Output result for demonstration purposes
    printf("Factorial of %d is %d\n", n, fact);
    return 0;
}