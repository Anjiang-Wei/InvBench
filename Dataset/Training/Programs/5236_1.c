#include <assert.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void reach_error() { assert(0); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

int calculate_threshold(int n, int increment) {
    int sum = 0;
    int i = 0;
    while (i < n) {
        sum += increment;
        i++;
        __VERIFIER_assert(sum == i * increment);
    }
    return sum;
}

int main() {
    int n = __VERIFIER_nondet_int();
    int increment = __VERIFIER_nondet_int();

    assume_abort_if_not(n > 0 && n <= 100);
    assume_abort_if_not(increment > 0 && increment <= 100);

    int total = calculate_threshold(n, increment);

    return 0;
}