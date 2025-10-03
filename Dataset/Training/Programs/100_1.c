#include <assert.h>
#include <stdlib.h>
void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    int sum = 0, prod = 1;

    // Assuming n is between 1 and 100
    assume_abort_if_not(n > 0 && n <= 100);

    // Calculate sum of first n integers and factorial of n
    while (n > 0) {
        sum = sum + n;
        prod = prod * n;
        n = n - 1;

        __VERIFIER_assert(sum >= 0);  // sum should always be non-negative
        __VERIFIER_assert(prod >= 1); // prod should always be positive
    }

    // To verify the mathematical correctness of sum
    // sum should be n*(n+1)/2 if loop runs correctly from original n to 0
    __VERIFIER_assert(sum == n * (n + 1) / 2 || (n == 0));

    return 0;
}