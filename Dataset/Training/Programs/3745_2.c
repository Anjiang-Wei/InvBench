#include <assert.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
   This program demonstrates searching for the greatest integer `m` such that `m*m <= k` for a given non-negative integer `k`.
   This essentially computes the integer square root of `k`.
*/
int main() {
    int k, m, square;
    k = __VERIFIER_nondet_int();

    assume_abort_if_not(k >= 0);

    m = 0;
    square = 0;

    while (square <= k) {

        m = m + 1;
        square = m * m;

        if (m > k + 1) {
            // Safety check to prevent infinite loops in case of errors
            break;
        }
    }

    // Adjust final result since the loop incremented m one past the valid integer square root
    m = m - 1;
    square = m * m;

    __VERIFIER_assert(square <= k);

    return 0;
}