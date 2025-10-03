extern void abort(void);
#include <assert.h>
void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main(void) {
    int a, b, i;

    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && a <= 5);

    b = __VERIFIER_nondet_int();
    assume_abort_if_not(b >= 0 && b <= 5);

    // Ensure "a" is less than "b"
    if (a >= b) {
        return 0;
    }

    int sum = 0;

    // Sum integers from "a" to "b" inclusive
    for (i = a; i <= b; i++) {
        sum += i;
    }

    // Verify that the sum matches the expected value using the formula for sum of integers
    int expected_sum = (b * (b + 1)) / 2 - (a * (a - 1)) / 2;
    __VERIFIER_assert(sum == expected_sum);

    return 0;
}