#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() {
    printf("Error reached\n");
    abort();
}

extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
    return;
}

int main() {
    int m, n;
    int a = 0, b = 1, sum = 0;

    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    // We assume m and n are non-negative and n > 0.
    assume_abort_if_not(m >= 0);
    assume_abort_if_not(n > 0);

    int i = 0, j = n;

    // The main logic is to accumulate sum in a complex way
    while (i < m) {
        // Adding some non-trivial constraints and changes
        sum += a + b;

        // Simulating a Fibonacci style increase
        int temp = b;
        b = a + b;
        a = temp;

        i++;

        if (j > 0) {
            j--;
        } else {
            j = n; // Reset j to n after it reaches zero
        }
    }

    // Post-condition: sum should be non-negative if m and n were non-negative
    __VERIFIER_assert(sum >= 0);

    return 0;
}