/*
  Sum of squares
  Computes s = 1^2 + 2^2 + ... + n^2 and verifies
  the closed‐form formula: 6*s == n*(n+1)*(2*n+1)
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "sum_squares.c", 9, "reach_error");
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
    long long i, s;

    /* choose n non-deterministically, but keep it small enough to prevent overflow */
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0);
    assume_abort_if_not(n <= 10000);

    i = 0;
    s = 0;

    /* before each iteration, 6*s == i*(i+1)*(2*i+1) */
    while (1) {
        __VERIFIER_assert(6 * s == i * (i + 1) * (2 * i + 1));

        if (!(i < n)) {
            break;
        }

        i = i + 1;
        s = s + i * i;
    }

    /* after the loop, 6*s == n*(n+1)*(2*n+1) */

    return 0;
}