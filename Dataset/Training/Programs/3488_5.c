#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }

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
    int n, sum, product;
    n = __VERIFIER_nondet_int();

    // Assume n to be a non-negative small integer
    assume_abort_if_not(n >= 0 && n <= 5);

    sum = 0;
    product = 1;

    for (int i = 1; i <= n; i++) {
        sum += i;
        product *= i;
    }

    // The series sum should be n(n+1)/2
    // The product should be the factorial of n
    switch (n) {
    case 0:
        break; // 0! = 1
    case 1:
        break; // 1! = 1
    case 2:
        break; // 2! = 2
    case 3:
        __VERIFIER_assert(product == 6);
        break; // 3! = 6
    case 4:
        break; // 4! = 24
    case 5:
        break; // 5! = 120
    default:
        reach_error();
    }

    printf("Sum of numbers: %d, Factorial: %d\n", sum, product);
    return 0;
}