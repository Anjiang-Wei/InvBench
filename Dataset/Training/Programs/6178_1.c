/* Program to count the number of even and odd numbers within a specified range */

#include <assert.h>
#include <stdio.h>

void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

extern unsigned int __VERIFIER_nondet_uint();

int main() {
    unsigned int n, i;
    unsigned int even_count = 0, odd_count = 0;

    n = __VERIFIER_nondet_uint(); // External input for the range limit
    if (n == 0) {
        return 0; // Avoid zero range
    }

    for (i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    // As a check, the total should be equal to the range
    __VERIFIER_assert(even_count + odd_count == n);

    // Output the results (optional for verification purposes)
    printf("Range: 1 to %u\n", n);
    printf("Even numbers: %u\n", even_count);
    printf("Odd numbers: %u\n", odd_count);

    return 0;
}