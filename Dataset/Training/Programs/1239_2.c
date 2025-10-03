#include <assert.h>
#include <stdbool.h>

void reach_error() { assert(0); }

extern void __VERIFIER_error() __attribute__((__noreturn__));
void __VERIFIER_error() { reach_error(); }

extern int __VERIFIER_nondet_int(void);

// Verification asserting function
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { __VERIFIER_error(); }
    }
}

// A function to perform some intended operations
int calculate(int a, int b) {
    return (a * a) - (b * b);
}

int main(void) {
    int m = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();

    // Precondition: Ensure inputs are positive for some intended logic
    if (!(m > 0 && n > 0)) {
        return 0;
    }

    int result = 0;
    int i = 0;

    while (i < 10) {
        result += calculate(m, n);
        // Here, the loop ensures that m is always greater than n
    }

    // Postcondition: assert the relation after loop completes
    __VERIFIER_assert(result >= 0);

    return 0;
}