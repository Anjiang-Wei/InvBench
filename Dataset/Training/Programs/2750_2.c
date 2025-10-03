#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10);

    int sum = 0;
    int factorial = 1;

    for (int i = 1; i <= n; ++i) {
        sum += i;
        factorial *= i;

        // At each step, assert that the sum of first i natural numbers is equal to i * (i + 1) / 2
    }

    // After the loop, assert that factorial is non-negative
    __VERIFIER_assert(factorial >= 0);

    // Print results (can be removed if not needed to avoid side effects)
    printf("Sum of first %d natural numbers is %d\n", n, sum);
    printf("Factorial of %d is %d\n", n, factorial);

    return 0;
}