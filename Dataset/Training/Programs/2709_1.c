#include <stdbool.h>
#include <stdio.h>

// External functions
extern void abort(void);
void reach_error() { abort(); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// A modified assert function
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Main program
int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n < 20); // Assume n is a reasonably small number

    int prev = 0;
    int current = 1;
    int next = 0;

    // Loop to calculate Fibonacci sequence
    for (int i = 2; i <= n; ++i) {
        next = prev + current;

        // Constraint: next should never overflow for small n
        __VERIFIER_assert(next > prev);

        prev = current;
        current = next;
    }

    // Final constraint to ensure the final state is as expected

    printf("F(%d) = %d\n", n, current); // Output the result
    return 0;
}