#include <assert.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int N = __VERIFIER_nondet_int();
    if (N <= 0) {
        return 0;
    }
    assume_abort_if_not(N < 1000); // Ensure N isn't too large for the demo

    int x = 0, y = 0;

    // Loop that simulates specific bounds invariants
    while (x < N) {
        x++;
        if (x % 2 == 0) {
            y += 2;
        } else {
            y += 3;
        }
    }

    // Check condition after the loop
    __VERIFIER_assert(y >= 2 * N && y <= 3 * N);

    return 0;
}