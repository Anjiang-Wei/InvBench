#include <assert.h>
#include <stdio.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    int sum_even = 0;
    int sum_odd = 0;
    int i;

    // We assume n is a non-negative integer
    if (n < 0) {
        return 0;
    }

    i = 1;

    while (i <= n) {
        if (i % 2 == 0) {
            sum_even += i;
        } else {
            sum_odd += i;
        }
        i++;
    }

    // After the loop, check that sum_even at least matches one of its divisors
    __VERIFIER_assert(sum_even % 2 == 0);

    // Print the results
    printf("Sum of even numbers: %d\n", sum_even);
    printf("Sum of odd numbers: %d\n", sum_odd);

    return 0;
}