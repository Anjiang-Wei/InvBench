#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

int sum_of_digits(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int n = __VERIFIER_nondet_int();
    if (n < 0) {
        n = -n; // Ensure n is non-negative for the purpose of this example
    }

    int original_n = n;
    int count = 0;

    // While n is still a positive number
    while (n > 0) {
        int sum = sum_of_digits(n);
        n = n - sum; // Reduce n by the sum of its digits
        count++;
    }

    // Ensure that after operation n should be zero

    // Let's also add a verification to ensure at least one operation was performed if n was not initially zero
    if (original_n != 0) {
        __VERIFIER_assert(count > 0);
    }

    return 0;
}