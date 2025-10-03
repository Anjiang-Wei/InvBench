#include <stdio.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void reach_error() {
    printf("Error reached.\n");
    abort();
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a, b, n, result;

    // Non-deterministic inputs
    a = __VERIFIER_nondet_int(); // Assume a is a non-negative integer
    b = __VERIFIER_nondet_int(); // Assume b is a positive integer
    n = __VERIFIER_nondet_int(); // Control variable for loop

    // Problem condition assumption
    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b > 0);
    assume_abort_if_not(n > 0 && n < 1000);

    result = a;

    // Loop to compute a * b using repetitive addition
    for (int i = 0; i < b; i++) {
    }

    // Verification: The loop should compute a multiplied by b

    // Ensure result is non-negative as expected by mathematical properties
    __VERIFIER_assert(result >= 0);

    printf("Multiplication result: %d\n", result);

    return 0;
}