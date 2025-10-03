// count_sum.c
// This program nondeterministically interleaves decrementing two non-negative counters x and y,
// counting each decrement in 'count'. It then asserts that count == original x + original y.

extern void abort(void);
#include <assert.h>

void reach_error() {
    assert(0);
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

extern _Bool __VERIFIER_nondet_bool(void);
extern int __VERIFIER_nondet_int(void);

int main() {
    int m = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();
    // only consider non-negative inputs
    if (m < 0 || n < 0) {
        return 0;
    }

    int x = m;
    int y = n;
    int count = 0;

    // loop until both x and y are zero, nondeterministically choosing
    // to decrement x or y when possible
    while (x > 0 || y > 0) {
        _Bool choice = __VERIFIER_nondet_bool();
        if (x > 0 && (choice || y == 0)) {
            // decrement x when either choice is true or y is already zero
            x--;
            count++;
        } else {
            // otherwise decrement y
            y--;
            count++;
        }
    }

    // at the end, we must have performed exactly m + n decrements
    __VERIFIER_assert(count == m + n);
    return 0;
}