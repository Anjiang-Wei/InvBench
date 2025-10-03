// New C program inspired by patterns observed in the given examples

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
extern void abort(void);
#include <assert.h>

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

// Function to count the number of set bits using Kernighan's algorithm
unsigned int count_set_bits(unsigned int num) {
    unsigned int count = 0;
    while (num) {
        num &= (num - 1);
        count++;
    }
    return count;
}

int main() {
    unsigned int num = __VERIFIER_nondet_uint();
    assume_abort_if_not(num > 0 && num < 1000000); // Constraint on num for safety

    unsigned int iter;
    unsigned int max_iterations = 32; // Arbitrarily chosen limit for iteration

    assume_abort_if_not(max_iterations < 64); // Ensuring max_iterations is a feasible number

    iter = 0;
    while (iter < max_iterations) {
        unsigned int set_bits_count = count_set_bits(num);
        printf("Set bits count for %u: %u\n", num, set_bits_count);

        if (set_bits_count % 2 == 0) {
            num >>= 1; // Right shift if count of set bits is even
        } else {
            num <<= 1; // Left shift if count of set bits is odd
            num += 1;  // Ensuring num remains positive and dynamic
        }
        __VERIFIER_assert(num > 0); // Assert that num stays positive
        iter++;
    }

    return 0;
}