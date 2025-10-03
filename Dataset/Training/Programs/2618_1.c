#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

_Bool __VERIFIER_nondet_bool();

// A helper function that pretends to compute a factorial but has a complex control flow
unsigned int compute_factorial(unsigned int n) {
    unsigned int result = 1;
    unsigned int i = 1;

    while (i <= n) {
        if (i > 10) { // Adding a fictitious constraint condition
            break;    // Ensure that this loop will terminate if i > 10
        }
        result *= i;
        i++;
    }

    return result;
}

int main() {
    unsigned int a = 0;
    unsigned int b = 5;

    // Simulating a complex loop that doubles `b` until an unspecified condition is met
    while (__VERIFIER_nondet_bool()) {
        b *= 2;
        if (b > 100) {
            break;
        }
    }

    // Use the compute_factorial function for some value
    unsigned int c = compute_factorial(b % 10);

    // Ensure some condition on `c` related to factorial logic
    __VERIFIER_assert(c < 1000000);

    printf("Computation ended with a = %u, b = %u, c = %u\n", a, b, c);

    return 0;
}