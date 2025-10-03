#include <stdio.h>
#include <stdlib.h>

// Function declarations
extern void abort(void);
void reach_error() { abort(); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int a, b, c;
    long long sum, prod;

    // Getting nondeterministic inputs
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    c = __VERIFIER_nondet_int();

    // Assuming a bound to ensure verification
    assume_abort_if_not(a > 0 && a < 10);
    assume_abort_if_not(b > 0 && b < 10);
    assume_abort_if_not(c > 0 && c < 10);

    sum = 0;
    prod = 1;

    // Using a loop to perform computations on a, b, and c
    for (int i = 0; i < a; i++) {
        sum += b;
        prod *= c;

        // Verifying expressions during loop iterations
        __VERIFIER_assert(prod > 0); // prod should always be positive within given range
    }

    // Check consistent state after finishing loop
    __VERIFIER_assert(sum == b * a);

    printf("Final Sum: %lld, Product: %lld\n", sum, prod);
    return 0;
}