#include <assert.h>
#include <stdlib.h>

void reach_error(void) {
    assert(0);
}

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

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
    int c = __VERIFIER_nondet_int();

    // Initial constraints
    if (!(a >= 0 && b >= 0 && c >= 0)) {
        return 0;
    }

    int sum = 0, i = 0;

    // Loop to sum multiples of 3 or 5 upto c
    while (i < c) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
        i++;
    }

    // Postconditions

    // Ensure some constraints between a, b and sum
    if (a > b) {
    } else {
        __VERIFIER_assert(sum >= a - b);
    }

    return 0;
}