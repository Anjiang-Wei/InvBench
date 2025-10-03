#include <assert.h>
#include <stdlib.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    // Initialization
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    // Precondition
    if (!(a > 0 && b > 0)) {
        return 0;
    }

    // Ensure 'a' is less than 'b' initially
    if (a >= b) {
        return 0;
    }

    // Aim to increment 'a' and decrement 'b' until they meet or cross
    while (a < b) {
        // a increases faster than b decreases
        if (a % 2 == 0) {
            a += 3;
        } else {
            a += 2;
        }

        if (b % 2 == 0) {
            b -= 1;
        } else {
            b -= 2;
        }
    }

    // Postcondition: They have crossed
    __VERIFIER_assert(a >= b && a <= b + 5);

    return 0;
}