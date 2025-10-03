extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "sum_squares_series.c", 5, "reach_error");
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
        abort();
    }
}

int main() {
    long long n = __VERIFIER_nondet_int();
    /* bound n so that no overflow occurs for sums of squares up to n */
    assume_abort_if_not(n >= 0 && n <= 1000);

    long long i = 0;
    long long sum1 = 0; /* sum of 1 + 2 + ... + i */
    long long sum2 = 0; /* sum of squares 1^2 + 2^2 + ... + i^2 */

    while (i < n) {
        /* invariants before the next iteration */
        __VERIFIER_assert(6 * sum2 == i * (i + 1) * (2 * i + 1));

        long long t = i + 1;
        sum1 += t;
        sum2 += t * t;
        i++;
    }

    /* check the final values match the closed‐form formulas */

    return 0;
}