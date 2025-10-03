#include <assert.h>
#include <stdbool.h>
extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}
extern int __VERIFIER_nondet_int(void);

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int sum = 0;
    int product = 1;
    int n = __VERIFIER_nondet_int();

    if (n < 1 || n > 20) {
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        sum += i;
        product *= i;

        // Ensure the sum is always less than or equal to the product,
        // if it happens, then reset product.
        if (sum > product) {
            product = i; // reset product if the sum surpasses it.
        }
    }

    // Verify that our result conditions are consistent
    __VERIFIER_assert(product >= max(1, n)); // The product must be atleast greater or equal to max(1, n)

    return 0;
}