#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int calculate_combinations(int n, int k) {
    if (k > n || k < 0) {
        return 0;
    }
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main() {
    int n = __VERIFIER_nondet_int();
    int k = __VERIFIER_nondet_int();

    if (n > 10 || n < 0 || k > 10 || k < 0) {
        return 0;
    }

    int combinations = calculate_combinations(n, k);

    // Ensure the result is valid
    __VERIFIER_assert(combinations >= 0);

    // Print results for debugging purposes
    printf("Combinations of %d choose %d is: %d\n", n, k, combinations);

    return 0;
}