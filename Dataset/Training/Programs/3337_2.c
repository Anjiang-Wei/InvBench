#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 4, "reach_error"); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

extern int __VERIFIER_nondet_int(void);
void *malloc(unsigned int size);

// Calculate factorial iteratively and ensure a known property in the process
int calculate_factorial_property(int n) {
    int factorial = 1;
    int sum = 0;

    for (int i = 1; i <= n; ++i) {
        factorial *= i;
        sum += i;

        // Property: sum of numbers from 1 to i = i * (i + 1) / 2
    }

    return factorial;
}

int main() {
    int n;
    n = __VERIFIER_nondet_int();

    // Assume n to be a reasonably small positive integer
    assume_abort_if_not(n >= 1 && n <= 12); // Limiting to prevent overflow in factorial calculation

    int result = calculate_factorial_property(n);

    // Validate factorial result (basic check)
    __VERIFIER_assert(result > 0); // factorial of positive integer should be greater than 0

    return 0;
}