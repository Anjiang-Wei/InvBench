#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int();
extern _Bool __VERIFIER_nondet_bool();
void assume_abort_if_not(int cond) {
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
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    int z = __VERIFIER_nondet_int();

    assume_abort_if_not(x > 0 && y > 0 && z > 0); // Assumptions to work with positive integers

    int gcd = 1; // Variable to store greatest common divisor

    // Ensuring the loop works for non-negative values
    for (int i = 1; i <= (x < y ? (x < z ? x : z) : (y < z ? y : z)); i++) {
        if (x % i == 0 && y % i == 0 && z % i == 0) {
            gcd = i;
        }
    }

    // Validate gcd functionality: gcd should divide x, y, z
    __VERIFIER_assert(x % gcd == 0 && y % gcd == 0 && z % gcd == 0);

    // Check a property specific to gcd
    int some_property = 2 * gcd - 1;

    return 0;
}