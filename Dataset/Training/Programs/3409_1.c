/* Program computing a sequence of operations with constraints */

#include <assert.h>
void reach_error(void) { assert(0); }

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
    int a, b, n, i, sum, prod;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(a > 0 && b > 0 && n > 0 && n <= 100);

    sum = a;
    prod = 1;

    i = 0;

    while (i < n) {
        prod *= b;
        sum += prod;

        if (sum > 1000) {
            break; // To avoid overflow-like situation
        }

        i++;
    }

    // Assertion to verify that if i reached n, sum is less or equal to 1000
    __VERIFIER_assert(i != n || sum <= 1000);

    return 0;
}