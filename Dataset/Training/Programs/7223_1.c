#include <assert.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int sum = 0;
    int product = 1;
    int i = 0;

    // Assume nondet inputs are within a reasonable range
    if (a < 0 || a > 10 || b < 0 || b > 10) {
        abort();
    }

    // Calculating sum and product of numbers from a to b
    // where a <= b
    assume_abort_if_not(a <= b);

    for (i = a; i <= b; i++) {
        sum += i;
        product *= i;
    }

    // Let's make sure the sum and product have valid values
    __VERIFIER_assert(sum >= 0);

    // Verification condition: sum is a triangle number

    return 0;
}