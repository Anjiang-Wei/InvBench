#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();

    // Precondition: Ensuring x and y are non-negative
    if (!(x >= 0 && y >= 0)) {
        return 0;
    }

    int sum = 0;
    int i = 0;

    // A loop that adds all numbers from 0 to x-1 to sum
    while (i < x) {
        sum += i;
        i++;
    }

    // A secondary loop to add y to sum, y times
    int j = 0;
    while (j < y) {
        sum += y;
        j++;
    }

    // Post condition to verify
    __VERIFIER_assert(sum >= 0); // The sum should always be non-negative

    return 0;
}