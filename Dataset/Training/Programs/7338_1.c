#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond);
void __VERIFIER_assume(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

int main() {
    int x, y, n;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= 1000);

    x = 0;
    y = 0;

    while (x < n) {
        x = x + 1;
        if (x % 2 == 0) {
            y = y + 2;
        }
        if (x % 3 == 0) {
            y = y - 1;
        }
    }

    // Assert that y has a specific property
    __VERIFIER_assert(y >= 0);
    return 0;
}