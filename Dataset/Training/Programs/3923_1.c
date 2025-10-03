#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();
    int sum, product = 1;

    assume_abort_if_not(a > 0);
    assume_abort_if_not(b > 0);

    sum = 0;

    // Loop to calculate the sum of numbers from 1 to 'a'
    for (int i = 1; i <= a; i++) {
        sum += i;
    }

    // Loop to calculate the product of b numbers
    // and check the property of c along the way
    for (int j = 1; j <= b && c > 0; j++) {
        product *= j;
        c--;
    }

    // Final assertion to verify specific property
    __VERIFIER_assert((sum > 0) && (product >= 1));

    printf("Sum: %d, Product: %d\n", sum, product);

    return 0;
}