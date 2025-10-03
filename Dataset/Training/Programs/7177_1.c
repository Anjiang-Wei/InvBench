#include <stdbool.h>
#include <stdio.h>

// Prototypes for external functions, simulating nondeterministic inputs
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 7, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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
    // Simulation of nondeterministic variables
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    // Constraints on input values
    assume_abort_if_not(a >= 0 && b >= 0);

    int p = 1;       // Product of numbers
    int sum = 0;     // Sum of numbers
    int counter = 0; // Counter for iterations
    int limit = 10;  // Limit for loop, can be made nondeterministic as well

    // Loop to perform operations
    while (counter < limit) {
        // Increment the sum and calculate product
        sum += a + b;
        p *= (a + b + 1);

        // Increment counter
        counter++;

        // Change the inputs nondeterministically after some iterations
        if (counter % 2 == 0) {
            a = __VERIFIER_nondet_int();
            b = __VERIFIER_nondet_int();
            assume_abort_if_not(a >= 0 && b >= 0);
        }
    }

    // Perform final assertions on computed values
    __VERIFIER_assert(sum >= 0);
}