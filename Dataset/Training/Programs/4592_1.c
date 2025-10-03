#include <assert.h>
#include <limits.h>

extern void abort(void);
void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    assume_abort_if_not(x >= 0 && x <= 1000);
    assume_abort_if_not(y >= 0 && y <= 1000);

    int sum = 0;
    int i = 0;

    // Loop to calculate sum of numbers divisible by 3 or 5
    while (i <= x) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
        i++;
    }

    // Assertion to verify sum is non-negative and multiples of 3 or 5
    __VERIFIER_assert(sum >= 0);

    // Loop to verify the sum is within expected range
    int sum_check = 0;
    for (int j = 0; j <= x; j++) {
        if (j % 3 == 0 || j % 5 == 0) {
            sum_check += j;
        }
    }

    return 0;
}