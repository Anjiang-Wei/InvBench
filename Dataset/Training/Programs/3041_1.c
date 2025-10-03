#include <stdio.h>
#include <stdlib.h>

// Function prototypes for verifier tools
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
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

int main(void) {
    int m, n;
    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    // Assume m and n are non-negative and not too large
    assume_abort_if_not(m >= 0 && m <= 10);
    assume_abort_if_not(n >= 0 && n <= 10);

    int result = 0;
    int counter = 0;

    // A simple loop to multiply m * n using repeated addition
    while (counter < n) {
        result += m;
        counter++;
    }

    // Check if the computed multiplication result is correct
    __VERIFIER_assert(result == m * n);

    printf("Multiplication result: %d\n", result);
    return 0;
}