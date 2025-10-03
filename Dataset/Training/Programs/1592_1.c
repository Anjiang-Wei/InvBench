/*
  Sum of squares program.
  Computes s = 1^2 + 2^2 + ... + n^2
  Verifies the well‐known formula: 6*s == n*(n+1)*(2*n+1)
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "sumsq.c", 9, "reach_error");
}

extern unsigned int __VERIFIER_nondet_uint(void);

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
    unsigned int n, n0, i;
    long long s;

    /* pick n in a small range so that the loop is bounded */
    n = __VERIFIER_nondet_uint();
    assume_abort_if_not(n <= 10);

    /* save original n for the final check */
    n0 = n;
    s = 0;
    i = 1;

    /* sum of squares loop */
    while (i <= n) {
        s += (long long)i * i;
        i++;
    }

    /* postcondition: 6*s == n*(n+1)*(2*n+1) */
    __VERIFIER_assert(6 * s == (long long)n0 * (n0 + 1) * (2 * n0 + 1));

    return 0;
}