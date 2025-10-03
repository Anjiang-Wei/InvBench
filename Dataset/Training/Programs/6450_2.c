#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_prog.c", 4, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int __VERIFIER_nondet_int();

int main() {
    int a, b, sum, product, count;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Assume that a and b are non-negative integers
    if (a < 0 || b < 0) {
        abort();
    }

    sum = 0;
    product = 1;
    count = 0;

    // Sum up first b natural numbers and compute product of first b integers starting from 1
    while (count < b) {
        sum += (count + 1);
        product *= (count + 1);
        count++;
    }

    // Assert that product is the factorial of b and sum is the sum of first b natural numbers
    __VERIFIER_assert((b == 0 && product == 1) || product != 0);

    printf("Sum of first %d natural numbers is: %d\n", b, sum);
    printf("Product of first %d natural numbers is (b!): %d\n", b, product);

    return 0;
}