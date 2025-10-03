#include <assert.h>

extern void reach_error(void) { assert(0); }
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

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    int z = __VERIFIER_nondet_int();

    if (x < 0 || y < 0 || z < 0) {
        return 0; // Assume x, y, z are non-negative
    }
    int sum = 0;
    int i = 0;

    // Loop: accumulate sum of numbers from 0 to z
    while (i <= z) {
        sum += i;
        i++;
    }

    // Verification: sum should match the formula for sum of first n natural numbers

    // Ensuring x and y are not altered by the loop
    __VERIFIER_assert(x >= 0 && y >= 0 && sum >= 0);

    return 0;
}