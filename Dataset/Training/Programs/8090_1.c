#include <assert.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);

void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int m = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();

    assume_abort_if_not(m > 0);
    assume_abort_if_not(n > 0);

    int sum1 = 0;
    int sum2 = 0;
    int counter = 0;

    // Two nested loops accumulate values
    while (counter < m) {
        int i = 0;
        while (i < n) {
            sum1 += i;
            i++;
        }
        sum2 += sum1;
        counter++;
    }

    // Verifying some properties related to the sums
    __VERIFIER_assert(sum1 >= 0);

    return 0;
}