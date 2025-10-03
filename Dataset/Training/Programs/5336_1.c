#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int __VERIFIER_nondet_int() {
    return rand() % 10 - 5; // Random integers in the range [-5, 4]
}

int main() {
    int a, b, n, sum, product;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n < 5); // Ensuring n is within a reasonable bound for loop iteration

    a = 1;
    b = 1;
    sum = 0;
    product = 1;

    for (int i = 0; i < n; ++i) {
        a += i;       // Incrementally updating 'a' to be 1 + sum of numbers from 0 to n-1
        b *= 2;       // Doubling 'b' each iteration
        sum += a;     // Accumulating sum of 'a'
        product *= b; // Accumulating product of 'b'
    }

    // Verify certain properties about the sum and product
    __VERIFIER_assert(sum >= n);                   // Sum should be at least n since a starts at 1 incrementingly
    __VERIFIER_assert(product % 2 == 0 || n == 0); // Product always should be an even number except when n = 0

    return 0;
}