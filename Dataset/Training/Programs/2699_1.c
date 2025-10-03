#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void reach_error() {
    printf("Reach Error\n");
    abort();
}

extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
    return;
}

int main() {
    int a = __VERIFIER_nondet_int(); // some input value
    int b = __VERIFIER_nondet_int(); // another input value

    assume_abort_if_not(a >= 0 && a <= 100);
    assume_abort_if_not(b >= 0 && b <= 100);

    int sum = 0;
    int product = 1;
    int i = 0;

    while (i < a) {
        sum += i;
        product *= (i + 1);
        i++;
    }

    __VERIFIER_assert(sum <= 5050); // Assert that sum of numbers from 0 to a-1 is at most 5050 (triangular number for 100)
    __VERIFIER_assert(product > 0); // Assert that product of numbers 1 to a is positive
    __VERIFIER_assert(a * b >= 0);  // Assert that non-negative a and b produce a non-negative product

    printf("Sum: %d, Product: %d, a*b: %d\n", sum, product, a * b);

    return 0;
}