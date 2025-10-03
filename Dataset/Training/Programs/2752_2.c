#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
}

/*
  The program aims to compute a specific pattern of numbers
  where z is the sum of squares of numbers from 1 to n,
  under the constraint that n must be non-negative and less than 10.
  The loop invariant checks that z is indeed the sum of squares up to y.
*/
int main() {
    int n = __VERIFIER_nondet_int();
    int y = 0;
    int z = 0;

    // Precondition: 0 <= n < 10
    if (!(0 <= n && n < 10)) {
        return 0;
    }

    while (y <= n) {
        z += y * y;
    }

    // Postcondition: z is the sum of squares of numbers from 1 to n
    __VERIFIER_assert(z == (n * (n + 1) * (2 * n + 1)) / 6);

    return 0;
}