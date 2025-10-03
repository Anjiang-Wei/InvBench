#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int a, b, n;
    long long sum_even, sum_odd;

    // Initialize nondeterministic values
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(a > 0 && a <= 100);
    assume_abort_if_not(b > 0 && b <= 100);
    assume_abort_if_not(n > 0 && n <= 100);

    sum_even = 0;
    sum_odd = 0;

    int i = 0;
    while (i < n) {
        if (i % 2 == 0) {
            sum_even += a * i;
        } else {
            sum_odd += b * i;
        }
        i++;
    }

    // Verify some simple properties
    __VERIFIER_assert(sum_odd >= 0);

    printf("Sum of even-indexed multiples of %d: %lld\n", a, sum_even);
    printf("Sum of odd-indexed multiples of %d: %lld\n", b, sum_odd);

    return 0;
}