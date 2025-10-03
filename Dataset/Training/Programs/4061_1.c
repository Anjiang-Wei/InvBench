#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

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
extern int __VERIFIER_nondet_int();
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();
    int x = 0, y = 0;

    // Assume conditions for meaningful computations
    assume_abort_if_not(a >= 0 && a <= 100);
    assume_abort_if_not(b >= 0 && b <= 20);
    assume_abort_if_not(c >= 0 && c <= 50);

    // Loop with conditions based on external input
    while (x < a) {
        y += b;
        x++;
        if (y >= 1000) {
            y -= c;
        }
    }

    // After the loop, evaluate the effect
    __VERIFIER_assert(x <= 100 && y >= 0);

    // Additional computation with a different structure
    int z = 1;
    for (int i = 0; i < b; i++) {
        if (z * 2 < y) {
            z *= 2;
        } else {
            z += 3;
        }
    }

    return 0;
}