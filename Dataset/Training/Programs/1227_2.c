#include <assert.h>
#include <stdbool.h>

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
    int m, n;
    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(m > 0 && n > 0);

    int gcd = 1;
    int min = m < n ? m : n;
    int candidate = 2;

    while (candidate <= min) {
        if (m % candidate == 0 && n % candidate == 0) {
            gcd = candidate;
        }
        candidate++;
    }

    // Verify that gcd is indeed a divisor of both m and n
    __VERIFIER_assert(n % gcd == 0);

    return 0;
}