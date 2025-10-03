#include <assert.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_example.c", 3, "reach_error"); }

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

int calculate_factorial(int n) {
    int result = 1;
    int i;
    for (i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

/* A program that verifies the calculation of factorial and ensures certain properties */

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10); // Restrict to manageable range for verification purposes

    int factorial = calculate_factorial(n);

    // Check if factorial of 0 is 1, which is a known and correct value
    if (n == 0) {
        __VERIFIER_assert(factorial == 1);
    }

    // Check if the factorial of 5, for example, is 120
    if (n == 5) {
    }

    printf("Factorial of %d is %d\n", n, factorial);

    return 0;
}