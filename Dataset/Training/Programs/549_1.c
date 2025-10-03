#include <assert.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void reach_error(void) { assert(0); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
        abort();
    }
}

int main() {
    // Step 1: Initialize three variables
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();

    // Step 2: Setting constraints
    if (!(a > 0 && a < 10)) {
        return 0;
    }
    if (!(b >= 10 && b < 20)) {
        return 0;
    }
    if (!(c >= 20 && c < 30)) {
        return 0;
    }

    // Step 3: A loop that modifies a and b
    while (__VERIFIER_nondet_bool()) {
        if (a < 10) {
            a += 2; // Increment 'a' to ensure it passes the bounds
        }
        if (b > 10) {
            b -= 1; // Decrement 'b' to ensure it approaches a stopping condition
        }

        // Intentionally no assertions here for invariants
    }

    // Step 4: Final assertion conditions
    __VERIFIER_assert(a >= 10 || b <= 10 || c >= 20);

    return 0;
}