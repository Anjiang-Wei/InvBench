#include <stdlib.h>

// Declare functions used for error handling and nondeterministic inputs
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "proposed.c", 8, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

// Simple assertion function
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// Main computationally meaningful program
int main(void) {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    // Assume positive values for simplicity
    if (a < 0 || b < 0) {
        return 1;
    }

    // Loop to transform the values iteratively
    while (b < 500) {
        a = a + 2;
        b = b * 2;
    }

    // A condition based on some transformed values
    int result = 3 * a + 5 * b;

    // Assert a meaningful condition on the final result
    __VERIFIER_assert(result >= a);

    return 0;
}