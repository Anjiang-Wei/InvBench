/*
 * A new C program inspired by benchmarking techniques
 * with constraints suitable for automated verification
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 14, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
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
}

int main() {
    int n = __VERIFIER_nondet_int();
    int sum = 0;
    int product = 1;

    // Assuming n is between 1 and 10
    assume_abort_if_not(n >= 1 && n <= 10);

    // Compute sum of first n numbers and factorial of n
    for (int i = 1; i <= n; i++) {
        sum += i;
        product *= i;
    }

    // Establish some condition on sum and product
    if (n <= 5) {
        __VERIFIER_assert(product <= 120); // n! for n <= 5 is at most 120
    } else {
        // In case n > 5, set a more relaxed condition
        __VERIFIER_assert(product >= sum);
    }

    return 0;
}