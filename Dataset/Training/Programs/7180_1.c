#include <assert.h>
#include <stdbool.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

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
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int p = __VERIFIER_nondet_int();
    int q = __VERIFIER_nondet_int();
    int steps = __VERIFIER_nondet_int();

    assume_abort_if_not(p > 0 && q > 0 && steps >= 0);

    int sum = 0;
    int product = 1;
    int counter = 0;

    while (__VERIFIER_nondet_bool() && counter < steps) {
        __VERIFIER_assert(sum == a * counter + b * counter);

        sum += a + b;
        product = product * 2 * (a + b);
        counter++;
    }

    return 0;
}