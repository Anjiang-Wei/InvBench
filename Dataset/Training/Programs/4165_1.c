#include <stdio.h>
#include <stdlib.h>

// Function declarations
extern void abort(void);
void reach_error() { abort(); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Function to verify the final condition
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

int main() {
    int a, n;
    int sum = 0, checksum = 0;

    // Non-deterministic inputs for 'a' and 'n'
    a = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    // Assumptions to limit the input values
    assume_abort_if_not(a >= 0 && a <= 10);
    assume_abort_if_not(n >= 0 && n <= 10);

    int i = 0;
    while (i < n) {
        sum = sum + a;
        checksum = checksum + (i + 1) * a;
        i++;
    }

    // Checksum verification
    __VERIFIER_assert(checksum == (n * (n + 1) / 2) * a);

    // Final output for verification tools
    return sum;
}