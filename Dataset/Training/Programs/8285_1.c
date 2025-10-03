#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "proposed_program.c", 3, "reach_error"); }

extern unsigned int __VERIFIER_nondet_uint(void);
extern void abort(void);
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
    unsigned int n, sum;
    unsigned int x, squaresSum, product;
    n = __VERIFIER_nondet_uint();

    // Ensure n is a non-negative integer less than or equal to 10
    assume_abort_if_not(n <= 10);

    sum = 0;
    squaresSum = 0;
    product = 1;

    x = 1;

    // Loop that computes factorial, sum of numbers, and sum of squares
    while (x <= n) {
        sum = sum + x;
        squaresSum = squaresSum + x * x;
        product = product * x;

        x = x + 1;
    }

    // Check the relation between sum of squares and square of sums for small n
    if (n != 0) {
        __VERIFIER_assert(squaresSum <= sum * sum);
    }

    // Print result
    printf("n: %u, Sum: %u, Sum of Squares: %u, Factorial: %u\n", n, sum, squaresSum, product);

    return 0;
}