#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "calculated_sequence.c", 7, "reach_error");
}

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

extern unsigned int __VERIFIER_nondet_uint(void);

int main() {
    unsigned int n = __VERIFIER_nondet_uint();
    assume_abort_if_not(n > 0 && n < 1000); // Assuming a valid range for simulation

    unsigned int i;
    unsigned int factorial = 1;
    unsigned int pre_factorial = 1;
    unsigned int sum = 0;

    // Compute factorial incrementally and list its running sum
    for (i = 1; i <= n; i++) {
        pre_factorial = factorial;
        factorial *= i;

        // Validating the incrementality: current factorial is previous factorial * current step i
        __VERIFIER_assert(factorial == pre_factorial * i);
        sum += factorial;

        // Ensure running sum is always greater than previous factorial
    }

    printf("Factorial(%u) = %u\n", n, factorial);
    printf("Sum of factorials up to %u = %u\n", n, sum);

    return 0;
}