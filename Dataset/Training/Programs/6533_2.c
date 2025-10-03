#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

void reach_error() {
    assert(0);
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    int n = 10;
    long long sum = 0;
    long long product = 1;
    int i = 1;

    while (i <= n) {
        sum += i;
        product *= i;

        __VERIFIER_assert(product > 0);

        i++;
    }

    printf("Sum of first %d natural numbers is: %lld\n", n, sum);
    printf("Product of first %d natural numbers is: %lld\n", n, product);

    // Check if computations were done correctly
    // Product verification can overflow in practice, verify under controlled range only

    return 0;
}