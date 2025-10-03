#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    int count = 0;

    // Assume some constraints on x and y
    assume_abort_if_not(x >= 0);
    assume_abort_if_not(y >= 0);

    // Constraint to ensure termination
    assume_abort_if_not(x < 50);

    while (x > 0) {
        // Perform a meaningful operation
        if (__VERIFIER_nondet_bool()) {
            y += x;
        } else {
            y -= x;
        }

        // Control variable operation to ensure termination
        x--;
        count++;
    }

    // Assert properties of interest
    // In this case, we assert that `count` should not exceed 50
    __VERIFIER_assert(count <= 50);
    return 0;
}