#include <assert.h>
#include <stdbool.h>

extern void abort(void);
void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);
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
    int a, b, x, y, sum;
    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && a <= 10);
    b = __VERIFIER_nondet_int();
    assume_abort_if_not(b >= 0 && b <= 10);

    x = 0;
    y = a;
    sum = 0;

    while (y > 0) {
        sum = sum + b;
        y = y - 1;
    }

    __VERIFIER_assert(sum == a * b);

    return 0;
}