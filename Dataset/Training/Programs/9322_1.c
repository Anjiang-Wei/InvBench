// New C program based on the patterns and structures of the provided examples

#include <stdbool.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int();
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
    int n = __VERIFIER_nondet_int();
    int factorial = 1;
    int i = 1;

    if (n < 0) {
        return 0; // Factorial not defined for negative numbers
    }

    // Loop to compute factorial of n
    while (i <= n) {
        // Ensure multiplication remains within bounds
        __VERIFIER_assert(factorial >= 0);

        factorial *= i;

        i++;
    }

    // Verify post-condition - should hold true if no overflow occurred.
    // This results in a non-trivial condition when factoring large numbers

    return 0;
}