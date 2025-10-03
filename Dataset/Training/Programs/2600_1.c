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

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a, b;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Assume a and b are positive and b is non-zero
    assume_abort_if_not(a > 0);
    assume_abort_if_not(b > 0);

    int count = 0;
    int sum = 0;

    while (sum < a) {
        sum += b;
        count++;
    }

    // Ensure that the loop logic worked correctly
    __VERIFIER_assert(count * b >= a);

    return 0;
}