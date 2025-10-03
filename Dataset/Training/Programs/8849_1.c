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

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

int main() {
    int a, b, c, n;
    a = 0;
    b = 1;
    c = 2;
    n = __VERIFIER_nondet_int();

    // Ensure n is positive to prevent infinite loops
    assume_abort_if_not(n > 0);

    // Loop to compute series based on indexing and control variables
    for (int i = 0; i < n; ++i) {
        int tmp = a + b * c;
        a = b;
        b = c;
        c = tmp;
    }

    // Perform a verification to ensure values do not exceed type limits
    __VERIFIER_assert(a >= 0 && b >= 0 && c >= 0);

    // Output the result for inspection
    printf("Results: a = %d, b = %d, c = %d, n = %d\n", a, b, c, n);

    return 0;
}