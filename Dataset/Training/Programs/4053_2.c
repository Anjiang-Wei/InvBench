#include <assert.h>
#include <limits.h>

extern void abort(void);
void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

#define MAX_ITER 50

int main() {
    int m, n;
    long long sum = 0;
    int count = 0;

    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    // Assume m and n are within reasonable bounds to prevent overflow
    assume_abort_if_not(m > 0 && m < 1000);
    assume_abort_if_not(n > 0 && n < 1000);

    while (count < MAX_ITER) {

        if (count >= n) {
            break;
        }

        sum += count;
        count++;
    }

    __VERIFIER_assert(sum - (long long)count * (count - 1) / 2 == 0);

    return 0;
}