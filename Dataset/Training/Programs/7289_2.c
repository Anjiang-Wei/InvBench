#include <stdio.h>
#include <stdlib.h>

// External functions declarations
extern void abort(void);
void reach_error() {
    printf("Error reached\n");
    abort();
}
extern void __VERIFIER_assert(int cond);

// Assert function to simulate the __VERIFIER_assert function
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
}

// Nondeterministic input generators
extern int __VERIFIER_nondet_int(void) {
    // Placeholder function simulating nondeterministic input
    return rand() % 2000 - 1000; // Returns a value between -1000 and 999
}

// Function to ensure some logical conditions for verification analysis
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();

    // Ensure y is non-zero to avoid division by zero
    assume_abort_if_not(y != 0);

    // Simple iteration logic modeling a computation
    int z = 0;
    int i;
    for (i = 0; i < x; i++) {
        z += y;
    }

    // Verify a complex condition after loop execution

    // Alternative computation with a verification condition
    int w = x * y;
    __VERIFIER_assert(w >= x || w < 0);

    // Output result for visibility
    printf("Computation result: w = %d\n", w);

    return 0;
}