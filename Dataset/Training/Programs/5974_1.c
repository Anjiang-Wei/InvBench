/*
Fibonacci Series with Constraints
Computes Fibonacci numbers and asserts a constraint on the sum of even-indexed Fibonacci numbers.
*/

#include <stdlib.h>
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci-constraint.c", 5, "reach_error"); }

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
    int n, counter = 0;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 2); // Ensuring n is greater than 2 for the Fibonacci series

    int a = 0, b = 1;
    int sum_even_indexed_fib = a; // Starting with the 0th index

    for (int i = 2; counter < 100 && i < n; ++i) {
        int next_fib = a + b;
        a = b;
        b = next_fib;

        if (i % 2 == 0) {
            sum_even_indexed_fib += next_fib;
        }

        // Assert that the sum of Fibonacci numbers up to any point is less than 4 times the maximum Fibonacci number up to that point
        __VERIFIER_assert(sum_even_indexed_fib < 4 * next_fib);

        counter++;
    }

    return 0;
}