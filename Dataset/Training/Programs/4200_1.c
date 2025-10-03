#include <assert.h>
#include <stdlib.h>

// Error reach function for verification purposes
void reach_error() { assert(0); }

// Function prototypes for the verifier's nondeterministic inputs
extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond);

// Custom assert function to use with the verifier
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

// The main function
int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c;
    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b >= 0);

    if (b == 0) {
        return 0; // Avoid division by zero
    }

    int quotient = 0;
    int remainder = a;

    while (remainder >= b) {
        remainder -= b;
        quotient++;
    }

    c = remainder + b * quotient;

    // Verify that the result of the computation matches the input
    __VERIFIER_assert(c == a);

    return 0;
}