#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* Problem:
   This program initializes three variables a, b, and counter.
   It verifies that as a and b are repeatedly incremented under certain conditions,
   the counter keeps track of the total number of increments, remaining within a calculated bound.
*/
int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int counter = 0;

    // Precondition: a starts between 0 and 10; b between 10 and 20.
    if (!(a >= 0 && a <= 10 && b >= 10 && b <= 20)) {
        return 0;
    }

    // Target boundary: defined by an initial difference augmented by random increments
    int boundary = b - a;

    while (__VERIFIER_nondet_bool()) {
        if (a < b) {
            a++;
        } else {
            b++;
        }
        counter++;

        // Maintain relationship: initial boundary plus counter should cover the range
    }

    // Postcondition: After loop, check the logical constraint on finished state
    __VERIFIER_assert(boundary <= 20);

    return 0;
}