#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

extern unsigned int __VERIFIER_nondet_uint();
extern int __VERIFIER_nondet_int();

int main() {
    unsigned int a = __VERIFIER_nondet_uint();
    unsigned int b = __VERIFIER_nondet_uint();

    // Ensure the number is small to avoid large loops during verification
    if (a >= 1000 || b >= 1000) {
        return 0;
    }

    unsigned int sum = 0;
    unsigned int product = 1;

    for (unsigned int i = 1; i <= a; i++) {
        sum += i;
        product *= i;
        if (product > 5000) {
            product = 1; // Prevent overflow related issues
        }
    }

    for (unsigned int j = 1; j <= b; j++) {
        sum += j;
        product *= j;
        if (product > 5000) {
            product = 1; // Prevent overflow related issues
        }
    }

    // Check that the product remains below a certain threshold
    __VERIFIER_assert(product <= 5000);

    printf("Sum: %u\n", sum);
    printf("Product: %u\n", product);

    return 0;
}