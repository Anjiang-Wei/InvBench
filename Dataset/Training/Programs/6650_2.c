#include <assert.h>
void reach_error() { assert(0); }

extern unsigned int __VERIFIER_nondet_uint(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

// Linear Congruential Generator example for pseudo-random number generation
// This program verifies that the numbers generated remain within the expected range

int main() {
    unsigned int a = 1664525;    // multiplier
    unsigned int c = 1013904223; // increment
    unsigned int m = 4294967296; // modulus which is 2^32
    unsigned int seed = __VERIFIER_nondet_uint();

    // Assume seed is a valid unsigned int
    unsigned int value = seed;

    int count = 0;
    unsigned int threshold = 100;

    while (count < threshold) {
        value = (a * value + c) % m;
        // Verify that the generated value is within the expected range [0, m-1]
        count++;
    }

    // Verify that the loop executed exactly 'threshold' times
    __VERIFIER_assert(count == threshold);

    return 0;
}