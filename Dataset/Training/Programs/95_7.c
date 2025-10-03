#include <assert.h>
#include <stdlib.h> // for abort()

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);
extern void abort(void);

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
    // nondeterministic inputs
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();

    // Precondition: x >= 0, y > 0, and not too large
    assume_abort_if_not(x >= 0 && y > 0 && x <= 1000 && y <= 1000);

    //
    // 1) Multiplication by repeated addition
    //
    int sum = 0;
    int count = y;
    // Loop builds sum == x * (original y - count)
    while (count > 0) {
        sum = sum + x;
        count = count - 1;
    }
    int product = sum;
    // Check that we computed x * y correctly

    //
    // 2) Division by repeated subtraction
    //    Compute quotient and remainder of product / x
    //
    int dividend = product;
    int divisor = x;
    int quotient = 0;
    int remainder = dividend;
    while (divisor > 0 && remainder >= divisor) {
        remainder = remainder - divisor;
        quotient = quotient + 1;
    }
    // quotient should be y, remainder should be 0

    //
    // 3) A loop with nondeterministic updates
    //    Build two counters p and q in y steps
    //
    int p = 0;
    int q = 0;
    int i = 0;
    while (i < y) {
        if (__VERIFIER_nondet_bool()) {
            p = p + 2;
        } else {
            p = p + 1;
        }
        if (__VERIFIER_nondet_bool()) {
            q = q + 3;
        } else {
            q = q + 1;
        }
        i = i + 1;
    }
    // Simple consistency checks

    //
    // 4) Nested loops: sum of squares from 0 to n-1
    //
    int n = y;
    int j = 0;
    int sum_sq = 0;
    while (j < n) {
        int k = 0;
        while (k <= j) {
            sum_sq = sum_sq + k * k;
            k = k + 1;
        }
        j = j + 1;
    }
    // Known formula: sum_{k=0..n-1} k^2 = (n-1)*n*(2n-1)/6

    //
    // 5) Fibonacci sequence up to index y
    //
    int a = 0; // fib(0)
    int b = 1; // fib(1)
    int idx = 0;
    while (idx < y && b >= 0) {
        int temp = a + b;
        a = b;
        b = temp;
        idx = idx + 1;
    }
    // After the loop:
    //   a == fib(y)
    //   b == fib(y+1)
    // For y > 1 we know fib(y) >= fib(y-1), and fib(y-1) == b - a
    if (y > 1) {
        __VERIFIER_assert(a >= (b - a));
    }

    return 0;
}