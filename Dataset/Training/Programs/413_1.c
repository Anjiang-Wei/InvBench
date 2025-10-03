#include <stdio.h>
#include <stdlib.h>

// External functions similar to those in verification tools
extern void abort(void);
void reach_error() { abort(); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

// A nondeterministic integer generator, placeholder for verification tools
int __VERIFIER_nondet_int() {
    return rand() % 201 - 100; // Simulate nondeterministic behavior
}

int main() {
    int a = __VERIFIER_nondet_int(); // Get a nondeterministic integer
    int b = __VERIFIER_nondet_int(); // Another nondeterministic integer
    assume_abort_if_not(a >= -100 && a <= 100);
    assume_abort_if_not(b >= -100 && b <= 100);

    int result = 0;
    int i;

    // Begin loop
    for (i = 0; i < 10; i++) {
        if (a > b) {
            result += a - b; // Accumulate the difference
        } else {
            result += b - a; // Accumulate the absolute difference
        }
    }

    // Post-condition assertion
    __VERIFIER_assert(result >= 0);

    // Output result (for testing purposes)
    printf("Result: %d\n", result);

    return 0;
}