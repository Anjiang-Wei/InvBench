// This C program is designed for verification.
// It is inspired by patterns from known verification programs, utilizing loops and conditions.

#include <assert.h>
#include <stdbool.h>

extern void abort(void);
void reach_error() {
    assert(0);
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);
extern void __VERIFIER_assume(int cond);

int main() {
    // Initialize variables
    int a = 0, b = 0, step = 1;

    // Ensure nondeterministic values for `step`
    step = __VERIFIER_nondet_int();
    __VERIFIER_assume(step > 0 && step < 5);

    // Perform operations in a loop
    while (a < 100) {
        a += step;
        b += 2 * step;

        if (a > 50) {
            a = 0; // Reset `a` when it surpasses 50
            b = 0; // Similarly reset `b`
        }
    }

    // Final assertion to check the relation between a and b
    __VERIFIER_assert(a == b / 2);

    return 0;
}