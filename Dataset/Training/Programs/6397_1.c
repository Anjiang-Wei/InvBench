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
    int n, target, sum, multiplier, factor;

    n = __VERIFIER_nondet_int();
    target = __VERIFIER_nondet_int();
    multiplier = __VERIFIER_nondet_int();
    factor = __VERIFIER_nondet_int();
    sum = 0;

    assume_abort_if_not(n >= 0 && target >= 0 && multiplier >= 1 && factor >= 1);

    for (int i = 0; i < n; ++i) {
        sum += i * multiplier;
        if (sum > target) {
            break;
        }
        sum += factor;
    }

    __VERIFIER_assert(sum >= 0);

    return 0;
}