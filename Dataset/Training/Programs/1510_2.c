#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// A function to calculate the factorial of a number iteratively
int factorial(int n) {
    assume_abort_if_not(n >= 0); // Ensure input is non-negative

    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int n = __VERIFIER_nondet_int();

    // Limit the value of n to a safe range to avoid overflow
    assume_abort_if_not(n >= 0 && n <= 12);

    int fact = factorial(n);

    // Verify that the computed factorial is greater than or equal to n! for n >= 0

    // Verify specific property for n = 5, which is 120
    if (n == 5) {
        __VERIFIER_assert(fact == 120);
    }

    printf("Factorial of %d is %d\n", n, fact);
    return 0;
}