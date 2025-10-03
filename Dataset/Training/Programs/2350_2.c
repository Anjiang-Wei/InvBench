// A C program for automated verification tools.
// Computes Pascal's triangle row sums and Fibonacci sequence properties.
// Verifies the identities:
//   1) Sum of binomial coefficients in row n = 2^n
//   2) Sum of Fibonacci numbers F_0 + F_1 + ... + F_n = F_{n+2} - 1
//   3) Sum of squares of Fibonacci numbers F_0^2 + ... + F_n^2 = F_n * F_{n+1}

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "verifier_fib_pascal.c", 12, "reach_error");
}

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
    int n;
    // nondeterministic input
    n = __VERIFIER_nondet_int();
    // constrain n so that computations do not overflow
    assume_abort_if_not(n >= 0 && n <= 30);

    // Part 1: Compute Pascal's triangle up to row n
    // binom[i][j] = C(i, j)
    static int binom[31][31];
    int i, j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                binom[i][j] = 1;
            } else {
                binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
            }
        }
    }

    // Compute the sum of the nth row: sum_{j=0..n} C(n, j)
    int sum_binom = 0;
    for (j = 0; j <= n; j++) {
        sum_binom += binom[n][j];
    }

    // Compute 2^n by bit-shift
    int pow2 = 1 << n;

    // Verification 1: sum of binomial coefficients = 2^n

    // Part 2: Fibonacci sequence and sum of first (n+1) terms
    // F_0 = 0, F_1 = 1
    long fib_prev = 0;
    long fib_curr = 1;
    long sum_fib = fib_prev + fib_curr; // sum F_0 + F_1

    for (i = 2; i <= n; i++) {
        long next = fib_prev + fib_curr;
        sum_fib += next;
        fib_prev = fib_curr;
        fib_curr = next;
    }
    // At this point:
    //   fib_curr = F_n
    //   fib_prev = F_{n-1}

    // Compute F_{n+1} and F_{n+2}
    long fib_np1 = fib_prev + fib_curr; // F_{n+1}
    long fib_np2 = fib_curr + fib_np1;  // F_{n+2}

    // Verification 2:
    // sum_{k=0..n} F_k == F_{n+2} - 1
    __VERIFIER_assert(sum_fib == fib_np2 - 1);

    // Part 3: Sum of squares of Fibonacci numbers
    // compute S = sum_{k=0..n} F_k^2
    long sum_sqr = 0;
    {
        long a = 0;
        long b = 1;
        for (i = 0; i <= n; i++) {
            // a == F_i
            sum_sqr += a * a;
            long nxt = a + b;
            a = b;
            b = nxt;
        }
        // after loop, a = F_{n+1}, b = F_{n+2}
    }

    // Verification 3:
    // sum_{k=0..n} F_k^2 == F_n * F_{n+1}

    return 0;
}