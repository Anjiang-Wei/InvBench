#include <stdio.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void reach_error() {
    printf("Error reached!\n");
    abort();
}

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
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int limit = __VERIFIER_nondet_int();
    assume_abort_if_not(limit > 0);

    // Ensure a and b are within the initial bounds
    if (!(0 <= a && a <= b && b < limit)) {
        return 0;
    }

    int sum = 0;
    int steps = 0;

    while (steps < limit) {
        if (a < b) {
            a += 2;
            sum += 3;
        } else {
            b += 2;
            sum += 4;
        }
        steps++;

        // Check a condition based on the current states of a and b

        if (sum > 100) {
            break;
        }
    }

    // A post-condition that should be true
    __VERIFIER_assert(steps <= limit);

    return 0;
}