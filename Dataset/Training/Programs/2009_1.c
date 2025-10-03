#include <assert.h>

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void reach_error(void) { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    if (a < 0) {
        a = -a; // Ensure a is non-negative
    }
    if (b <= 0) {
        return 0; // Ensure b is positive
    }

    // Finding gcd(a, b) using the Euclidean algorithm
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }

    // Verification: At this point, a and b should be equal and non-zero
    __VERIFIER_assert(a > 0 && a == b);

    return 0;
}