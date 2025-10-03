#include <assert.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int m = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();
    int sum = 0, product = 1;

    // Assume n greater than or equal to 1 to avoid infinite loops.
    if (n < 1 || m < 1) {
        return 0;
    }

    // Calculate the sum and product of first 'n' natural numbers.
    int i = 1;
    while (i <= n) {
        sum += i;
        product *= i;
        i++;
    }

    // Product should be n! for n numbers.
    __VERIFIER_assert(product >= 0);

    // Calculating factorial affects overflow, ensure it's within typical limit.
    int limit = 20;

    int known_sum = ((n * (n + 1)) / 2);

    return 0;
}