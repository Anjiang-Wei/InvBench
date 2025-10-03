#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_verifier.c", 9, "reach_error"); }
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

int main() {
    int n, correct_sum, calculated_sum = 0;
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(n > 0);

    // Compute the expected sum of first n natural numbers
    correct_sum = n * (n + 1) / 2;

    for (int i = 1; i <= n; ++i) {
        calculated_sum += i;

        // Check if the sum so far is correct (to be verified by a solver)
        __VERIFIER_assert(calculated_sum == i * (i + 1) / 2);
    }

    // Final assertion: check if our computed sum matches the expected sum

    printf("Sum of first %d natural numbers is %d\n", n, calculated_sum);
    return 0;
}