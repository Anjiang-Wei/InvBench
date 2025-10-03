// Sum and Sum of Squares Verification
// Computes sum = 1 + 2 + ... + n and sqsum = 1^2 + 2^2 + ... + n^2
// and checks the well-known formulas:
//   sum   = n*(n+1)/2
//   sqsum = n*(n+1)*(2*n+1)/6

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "sum_squares.c", 14, "reach_error");
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
    long long sum, sqsum;
    int c;

    // pick a non‐deterministic input and constrain its range
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 100);

    sum = 0;
    sqsum = 0;
    c = 0;

    // loop to accumulate sum and sum of squares
    while (1) {
        // check the arithmetic relations at each step:
        //   2*sum   == c*(c+1)
        //   6*sqsum == c*(c+1)*(2*c+1)
        __VERIFIER_assert(
            2 * sum == (long long)c * (c + 1) &&
            6 * sqsum == (long long)c * (c + 1) * (2 * c + 1));

        if (!(c < n)) {
            break;
        }

        c++;
        sum += c;
        sqsum += (long long)c * c;
    }

    // final check: for c == n

    return 0;
}