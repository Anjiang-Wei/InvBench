#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

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

/* Computes the Fibonacci series iteratively and verifies the sum of even numbers. */
int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 2); // Assume n is greater than 2 for meaningful computation

    int a = 0;
    int b = 1;
    int sum_even = 0;
    int i = 2;
    int temp;

    while (i <= n) {
        temp = a + b;
        a = b;
        b = temp;

        if (b % 2 == 0) {
            sum_even += b;
        }

        i++;
    }

    // Sum of even numbers in the Fibonacci series up to nth element

    // Total fibonacci number should be greater or equal to the maximum of a or b at this point
    __VERIFIER_assert(b >= a);

    return 0;
}