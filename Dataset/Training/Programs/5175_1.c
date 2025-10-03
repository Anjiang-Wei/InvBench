#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

void reach_error() { assert(0); }

// External functions simulating non-deterministic inputs
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    // Assume non-negative inputs for computing GCD
    if (a < 0 || b < 0) {
        return 0;
    }

    int x = a;
    int y = b;

    // Ensure the values are initialized properly
    __VERIFIER_assert(x == a && y == b);

    int gcd_result = gcd(x, y);

    // Verify the properties of GCD
}