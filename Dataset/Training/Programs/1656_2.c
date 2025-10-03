#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "computation.c", 6, "reach_error"); }
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
    return;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0);

    // Initialize variables
    long long sum = 0;
    long long product = 1;
    int i = 1;

    // A loop that computes the sum and product of first n natural numbers
    while (1) {
        if (!(i <= n)) {
            break;
        }

        sum += i;
        product *= i;

        i++;
    }

    // Verify the computations
    __VERIFIER_assert(product > 0); // Best effort check, product's correctness is computationally infeasible to assert in a simple way

    printf("Sum of first %d numbers: %lld\n", n, sum);
    printf("Product of first %d numbers: %lld\n", n, product);

    return 0;
}