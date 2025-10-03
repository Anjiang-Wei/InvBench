#include <assert.h>
extern void abort(void);
extern int __VERIFIER_nondet_int(void);

// Error handling function
void reach_error() { assert(0); }

// Check if a condition is true, aborting the program if it's false
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Assert function to check conditions during execution
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Main computational function
int main() {
    int x, y, z;

    // Non-deterministically initialize variables
    x = __VERIFIER_nondet_int();
    y = __VERIFIER_nondet_int();
    z = __VERIFIER_nondet_int();

    // Assume y is a positive integer to avoid division by zero
    assume_abort_if_not(y > 0);

    int sum = 0;
    int product = 1;

    // Sum and product calculations based on constraints
    if (x >= 0 && y >= 0 && z >= 0) {
        for (int i = 0; i < 10; i++) {
            sum += (x + y + z);
            product *= (1 + x + y + z) % 4;
        }
    }

    // Check if the sum achieved a certain threshold
    __VERIFIER_assert(sum >= 0);

    // Check if the product has a specific constraint

    return 0;
}