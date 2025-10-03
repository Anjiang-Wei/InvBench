#include <assert.h>
#include <stdio.h>

// Function prototypes for external verification tools
extern void abort(void);
void reach_error() { abort(); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Function for asserting a condition
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    // Variables
    int a, b, sum, prod, diff;
    int counter = 0;

    // Nondeterministic initialization
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Assumptions about inputs
    assume_abort_if_not(b != 0);
    assume_abort_if_not(a >= 0 && a <= 50);
    assume_abort_if_not(b >= 1 && b <= 50);

    // Initialize result variables
    sum = 0;
    prod = 1;
    diff = a;

    // Main computational loop
    while (counter++ < 100) {
        // Calculate the running sum of a
        sum += a;

        // Calculate the running product modulo b
        prod = (prod * a) % b;

        // Calculate the difference between a and sum
        diff -= a;

        // Break if the difference equals zero, simulating a condition
        if (diff == 0) {
            break;
        }

        // Adjust `a` to reach the break condition eventually
        a--;
    }

    // Final assertions (Properties we expect to hold)
    __VERIFIER_assert(sum >= 0);  // Sum can't be negative
    __VERIFIER_assert(prod >= 0); // Product in modular arithmetic should be positive
    __VERIFIER_assert(diff <= 0); // Difference should not exceed the initial sum of a

    printf("Final Values -> Sum: %d, Product: %d, Difference: %d\n", sum, prod, diff);
    return 0;
}