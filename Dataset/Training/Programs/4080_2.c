#include <assert.h>
extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}
extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a, b, i, sum_a, sum_b;

    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && a <= 100);

    b = __VERIFIER_nondet_int();
    assume_abort_if_not(b >= 0 && b <= 100);

    sum_a = 0;
    sum_b = 0;

    for (i = 0; i < 10; i++) {
        sum_a += a;
        sum_b += b;

        __VERIFIER_assert(sum_b <= b * 10);
    }

    return 0;
}