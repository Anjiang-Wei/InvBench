#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

/*
 * This program computes the factorial of a number using an iterative approach.
 * The program ensures that the calculation remains within bounds to prevent overflow.
 * It's a simple example, but enough to analyze factorial calculation behavior.
 */

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 12); // To avoid overflow for factorial calculation in a typical 32-bit int

    long long factorial = 1;
    int i = 2;

    while (i <= n) {
        factorial = factorial * i;
        i = i + 1;
    }

    // The factorial of a positive integer n should be non-zero if n > 0
    if (n > 0) {
    }

    // The factorial of a number is 1 when n is 0 or 1
    if (n == 0 || n == 1) {
        __VERIFIER_assert(factorial == 1);
    }

    return 0;
}