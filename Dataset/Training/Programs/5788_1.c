#include <assert.h>
#include <stdbool.h>

extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}
extern int __VERIFIER_nondet_int(void);

// This function provides a hint to the solver to only abort if a condition is not met
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a = 0;
    int b = 0;
    int sum = 0;
    int limit;

    // Obtain a non-deterministic input for the limit
    limit = __VERIFIER_nondet_int();
    assume_abort_if_not(limit > 0);

    while (a < 100) {
        if (a % 2 == 0) {
            sum += a;
            b--;
        } else {
            sum -= b;
            b++;
        }
        a++;

        // Check conditions similar to loop invariants without being explicit
        if (a >= limit) {
            break;
        }
    }

    // Final verification, adapted to the specifics of the program logic.
    __VERIFIER_assert((sum >= 0 && b <= 0) || (sum <= 0 && b >= 0));

    return 0;
}