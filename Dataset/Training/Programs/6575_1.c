#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "complex_calculation.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int __VERIFIER_nondet_int(void) {
    // Simulate a nondeterministic integer with a safe value
    return rand() % 100;
}

int main(void) {
    unsigned int n = 0;
    unsigned int sum = 0;
    unsigned int product = 1;
    unsigned int num_even = 0;
    unsigned int num_odd = 0;

    // Let n be a non-deterministic number that is reasonable for computation; less than or equal to 50
    n = __VERIFIER_nondet_int();
    if (n > 50) {
        return 0;
    }

    unsigned int i;
    for (i = 0; i < n; i++) {
        sum += i;

        if (i % 2 == 0) {
            product *= (i + 1);
            num_even++;
        } else {
            num_odd++;
        }
    }

    printf("Sum of integers from 0 to %d: %u\n", n - 1, sum);
    printf("Product of even-indexed +1 numbers: %u\n", product);
    printf("Number of even indices: %u\n", num_even);
    printf("Number of odd indices: %u\n", num_odd);

    // Important condition: for n numbers from 0 to n-1, there should be exactly n numbers summed up
    __VERIFIER_assert((num_even + num_odd) == n);

    return 0;
}