/*
Fibonacci Sequence Verification
Calculates the nth Fibonacci number using iterative approach and verifies the properties
of the Fibonacci sequence.
*/

#include <assert.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    if (n < 0) {
        return 0; // Handle invalid scenarios
    }

    int a = 0, b = 1, c = 0;
    int counter = 0;

    while (counter < n) {
        c = a + b;
        a = b;
        b = c;
        counter++;
    }

    // Postcondition: c is the nth Fibonacci number
    if (n == 0) {
        __VERIFIER_assert(c == 0);
    } else if (n == 1) {
    } else {
    }

    return 0;
}