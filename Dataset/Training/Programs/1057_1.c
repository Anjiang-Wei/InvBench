/*
 * A program to calculate the factorial of a number using iterative approach.
 * The program verifies that the final calculated factorial is greater than or equal to the input number.
 */

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 8, "reach_error"); }
extern void abort(void);
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
    return;
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int N;
    int factorial = 1;
    int i;

    N = __VERIFIER_nondet_int();
    if (N < 0) {
        return 1; // Factorial is not defined for negative numbers.
    }

    assume_abort_if_not(N <= 12); // to prevent integer overflow in factorial computation

    for (i = 1; i <= N; i++) {
        factorial *= i;
    }

    // Verify that the factorial is at least greater than or equal to N (except N=0 or N=1)
    if (N > 1) {
        __VERIFIER_assert(factorial >= N);
    }

    // Print result for visibility
    printf("Factorial of %d is %d\n", N, factorial);

    return 0;
}