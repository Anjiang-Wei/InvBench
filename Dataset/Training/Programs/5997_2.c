#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() {
    printf("Error reached!\n");
    abort();
}

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    if (x <= 0 || y <= 0) {
        return 0;
    }

    int sum_of_primes = 0;
    int product_check = 1;

    while (x > 0) {
        if (is_prime(x)) {
            sum_of_primes += x;
        }

        if (__VERIFIER_nondet_bool()) {
            product_check *= (y % 3) + 1; // Ensure product_check is always positive
        }

        x--;
    }

    // Verify some properties after loop execution
    __VERIFIER_assert(product_check > 0);

    printf("Sum of primes: %d\n", sum_of_primes);
    printf("Product check: %d\n", product_check);

    return 0;
}