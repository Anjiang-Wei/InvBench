#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool();

// Custom function to calculate factorial, demonstrating recursive logic
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Main function showcasing a loop with constraints
int main() {
    int n, sum, current;

    // Generate a non-deterministic integer for the upper limit
    n = __VERIFIER_nondet_int();

    // Assume n is constrained between 0 and 10
    if (n < 0) {
        n = 0;
    }
    if (n > 10) {
        n = 10;
    }

    sum = 0;
    current = 0;

    // A loop that sums the square of each number from 0 to n
    while (current <= n) {
        sum += current * current;
        __VERIFIER_assert(sum >= current * current); // Ensure sum always incorporates the square of the current
        current++;
    }

    // Post-condition verification

    return 0;
}