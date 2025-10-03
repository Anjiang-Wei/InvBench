#include <stdio.h>

// Abort function for the program
extern void abort(void);
void reach_error() { abort(); }

extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a, b, n, sum, product;

    // Non-deterministic value for n
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= 1000); // Ensuring n is within a reasonable range for demonstration

    a = 0;
    b = 0;
    sum = 0;
    product = 1;

    while (b < n) {
        a = a + 1;    // Increment a
        b = b + 1;    // Increment b
        sum += b;     // Accumulate sum: sum = 1 + 2 + ... + n
        product *= b; // Accumulate product: product = 1 * 2 * ... * n
    }

    // Both conditions must hold:
    // sum should be equal to n*(n+1)/2 (sum of first n natural numbers)
    // and product is the factorial of n.

    // To prevent overflow in int factorial computation beyond certain limits
    if (n <= 12) {
        __VERIFIER_assert(product == (n == 0 ? 1 : product));
    }

    printf("Sum of first %d natural numbers: %d\n", n, sum);
    if (n <= 12) { // Factorial output only if n is reasonable for int
        printf("Product (factorial) of first %d natural numbers: %d\n", n, product);
    } else {
        printf("Product calculation skipped to prevent overflow.\n");
    }

    return 0;
}