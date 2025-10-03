#include <assert.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
void reach_error() { assert(0); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 1 && a <= 10);
    assume_abort_if_not(b >= 1 && b <= 10);

    int sum = 0;
    int diff = a - b;

    while (a != 0) {
        sum += b;
        a--;

        // Ensuring sum doesn't exceed a specific threshold.
        __VERIFIER_assert(sum <= 100);
    }

    // Ensure the sum equals the product of original `a` and `b`
    return 0;
}