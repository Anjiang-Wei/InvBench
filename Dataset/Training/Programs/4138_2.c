#include <stdio.h>
#include <stdlib.h>

// Verification utilities
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 3, "reach_error"); }
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

int compute_factorial(int n) {
    int result = 1;
    int i = 1;

    while (i <= n) {
        result *= i;
        i++;
    }

    return result;
}

int main() {
    int n = __VERIFIER_nondet_int();
    int factorial;

    // Assume n is a non-negative integer within reasonable bounds (e.g., 0 to 10)
    assume_abort_if_not(n >= 0 && n <= 10);

    factorial = compute_factorial(n);

    // Check the correctness of the factorial calculation
    if (n > 0) {
    } else {
        __VERIFIER_assert(factorial == 1);
    }

    printf("Factorial of %d is %d\n", n, factorial);

    return 0;
}