#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int n, m, p, q;
    n = __VERIFIER_nondet_int();
    m = __VERIFIER_nondet_int();
    p = __VERIFIER_nondet_int();
    q = __VERIFIER_nondet_int();

    // Assume the inputs are positive
    if (n < 0) {
        n = 0;
    }
    if (m < 0) {
        m = 0;
    }
    if (p < 0) {
        p = 0;
    }
    if (q < 0) {
        q = 0;
    }

    // Example constraint logic using loop
    int sum = 0, prod = 1;
    int i, j;
    for (i = 1; i <= n; i++) {
        sum += i;
        prod *= i;
        if (prod > 10) {
            prod = 1; // Reset product for demonstration
        }
    }

    for (j = 1; j <= m; j++) {
        sum += j;
        if (sum % 5 == 0) {
            break; // End loop early if a condition is met
        }
    }

    // Example constraints to verify - these aren't loop invariants
    __VERIFIER_assert(prod >= 1 || prod == 0);

    printf("Final Sum: %d, Final Product: %d\n", sum, prod);
    return 0;
}