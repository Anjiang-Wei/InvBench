#include <assert.h>
#include <limits.h>

extern void abort(void);
void reach_error() { assert(0); }
extern unsigned __VERIFIER_nondet_uint(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    unsigned n;
    unsigned long long factorial = 1, sum_of_squares = 0;
    int i = 1;

    n = __VERIFIER_nondet_uint();
    assume_abort_if_not(n < 20); // prevent overflow in factorial calculation

    while (i <= n) {
        factorial = factorial * i;
        sum_of_squares += i * i;
        i++;
    }

    // Verify that the sum of squares satisfies a relation when n is 5
    // This is just one example condition to make sure the program has verifiable behavior
    if (n == 5) {
        __VERIFIER_assert(sum_of_squares == 55); // 1^2 + 2^2 + ... + 5^2 = 55
    }

    return 0;
}