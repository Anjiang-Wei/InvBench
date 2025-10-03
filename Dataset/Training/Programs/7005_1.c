#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
extern void assume_abort_if_not(int cond) {
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
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();

    // Precondition: x and y are in a specific range
    assume_abort_if_not(x >= 0 && x <= 100);
    assume_abort_if_not(y >= 0 && y <= 100);

    int z = 0;
    int sum = 0;

    while (z < x + y) {
        if (z < x) {
            sum = sum + z;
        } else {
            sum = sum + (z - x);
        }
        z++;
    }

    // Postcondition checking
    __VERIFIER_assert(sum >= 0);

    return 0;
}