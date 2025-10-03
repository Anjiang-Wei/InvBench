#include <assert.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int sum = 0;
    int product = 1;

    // Assume initial constraints
    if (!(a > 0 && a < 10 && b > 0 && b < 10)) {
        return 0;
    }

    // Loop to calculate sum of all integers from 1 to a, and product of all integers from 1 to b
    int i = 1, j = 1;
    while (i <= a || j <= b) {
        if (i <= a) {
            sum += i;
            i++;
        }
        if (j <= b) {
            product *= j;
            j++;
        }
    }

    // Verify some properties
    __VERIFIER_assert(product >= 1);

    return 0;
}