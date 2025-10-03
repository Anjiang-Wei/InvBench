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
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0);

    long long factorial = 1;
    int multiplier = 1;

    while (multiplier <= n) {
        factorial *= multiplier;
        multiplier++;
    }

    // Partial application of assertions to make the program verifiable
    __VERIFIER_assert(factorial >= 1);      // Factorial of any positive number >= 1
    __VERIFIER_assert(multiplier == n + 1); // Ensures loop iterated n times

    return 0;
}