#include <assert.h>
#include <stdio.h>

extern int __VERIFIER_nondet_int(void);
void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
    return;
}

int compute_sum_product(int n, int *finalProduct) {
    int sum = 0;
    int product = 1;
    for (int i = 1; i <= n; i++) {
        sum += i;
        product *= i;
    }
    *finalProduct = product;
    return sum;
}

int main() {
    int n = __VERIFIER_nondet_int();
    if (n < 0 || n > 10) {
        return 0; // Precondition check
    }

    int product;
    int sum = compute_sum_product(n, &product);

    // Postconditions for verification
    __VERIFIER_assert(sum == (n * (n + 1)) / 2);

    printf("Sum of first %d numbers is %d\n", n, sum);
    printf("Product of first %d numbers is %d\n", n, product);

    return 0;
}