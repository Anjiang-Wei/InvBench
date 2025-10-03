#include <assert.h>
#include <stdio.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

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
    int n, sum, i, input;
    sum = 0;

    // Assume a reasonable non-negative upper limit
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 100);

    // Read `n` numbers and find their sum
    for (i = 0; i < n; i++) {
        input = __VERIFIER_nondet_int();
        assume_abort_if_not(input >= 0 && input <= 10); // Assume inputs in a fixed range
        sum += input;
    }

    printf("Total Sum: %d\n", sum);

    // Ensure the sum is within an acceptable range
    __VERIFIER_assert(sum >= 0 && sum <= n * 10);

    return 0;
}