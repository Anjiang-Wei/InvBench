#include <assert.h>
#include <stdio.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a, b, m, n;

    // Initialize variables
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && b >= 0);

    m = 0;
    n = 0;

    // Compute greatest common divisor (GCD)
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    m = a; // GCD of the initial inputs

    // Additional loop with some meaningful constraints
    while (n < 100) {
        n++;
        if (m > 1) {
            m--;
        }
    }

    // Ensure the constraint condition holds
    __VERIFIER_assert(m <= a);

    printf("Final value of m: %d\n", m);
    return 0;
}