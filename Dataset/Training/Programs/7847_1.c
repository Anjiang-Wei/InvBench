#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

/*
This program maintains a sum of squares condition where sum = a^2 + b^2.
The loop modifies `a`, `b`, and `sum` such that sum = a^2 + b^2 remains true.
*/

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int sum = __VERIFIER_nondet_int();

    // Ensure initial condition is valid
    assume_abort_if_not(sum == a * a + b * b);

    while (__VERIFIER_nondet_bool()) {
        int choice = __VERIFIER_nondet_int() % 4; // Random choice for modification

        if (choice == 0) {
            a += 1;
            sum = a * a + b * b;
        } else if (choice == 1) {
            if (a > 0) {
                a -= 1;
                sum = a * a + b * b;
            }
        } else if (choice == 2) {
            b += 1;
            sum = a * a + b * b;
        } else if (choice == 3) {
            if (b > 0) {
                b -= 1;
                sum = a * a + b * b;
            }
        }
    }

    // Ensure the sum of squares equality remains
    __VERIFIER_assert(sum == a * a + b * b);
    return 0;
}