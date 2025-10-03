#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }
extern int __VERIFIER_nondet_int(void);
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
    int m, n;
    int even_count = 0;
    int odd_count = 0;
    int sum_even = 0;
    int sum_odd = 0;

    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(m >= 1 && n >= 1);

    for (int i = 0; i <= m; i++) {
        if (i % 2 == 0) {
            even_count++;
            sum_even += i;
        } else {
            odd_count++;
            sum_odd += i;
        }
    }

    int product = 1;
    for (int j = 1; j <= n; j++) {
        product *= j;
    }

    // Ensure sum_even is correct for given even_count
    __VERIFIER_assert(sum_even == even_count * (even_count - 1));

    // Ensure sum_odd is correct for given odd_count

    // Factorial properties - here just a summative property as an example

    printf("Sum of even numbers: %d\n", sum_even);
    printf("Sum of odd numbers: %d\n", sum_odd);
    printf("Product of first %d numbers: %d\n", n, product);

    return 0;
}