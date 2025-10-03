#include <assert.h>
#include <stdlib.h>

extern void abort(void);
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
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
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int result = 1;
    int multiplier = 2;
    int counter = 0;

    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b > 0); // Ensure b is positive

    while (counter++ < 15) {
        a -= b;

        if (a < 0) {
            break; // Exit the loop if `a` becomes negative
        }

        // Only multiply result if a is guaranteed non-negative
        result *= multiplier;
    }

    // Ensure the result doesn't exceed a certain threshold
    __VERIFIER_assert(result <= 32768);

    return 0;
}