#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
void reach_error() {
    assert(0);
    abort();
}
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

int main() {
    int a, r, n;
    long long sum = 0;

    a = __VERIFIER_nondet_int(); // initial term
    assume_abort_if_not(a >= 0 && a <= 100);

    r = __VERIFIER_nondet_int(); // common ratio
    assume_abort_if_not(r >= 0 && r <= 10);

    n = __VERIFIER_nondet_int(); // number of terms
    assume_abort_if_not(n >= 0 && n <= 50);

    int current_term = a;
    int i;

    for (i = 0; i < n; i++) {
        __VERIFIER_assert(sum + current_term >= sum); // Ensure no overflow
        sum += current_term;
        current_term *= r;
    }

    return 0;
}