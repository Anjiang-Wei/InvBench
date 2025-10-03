/*
  Sum of Squares
  Computes sum = 1^2 + 2^2 + ... + n^2
  and checks the well-known formula:
    6 * sum == n * (n + 1) * (2*n + 1)
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "sum_squares.c", 7, "reach_error");
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
    long long sum;
    int i;

    /* non-deterministic input n, but bound it to avoid overflow */
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 10000);

    sum = 0;
    i = 1;

    /* loop accumulating squares, checking the partial formula at each step */
    while (1) {
        sum += (long long)i * i;

        /* Invariant check: after adding i^2,
           6*sum == i*(i+1)*(2*i+1) holds for all i >= 1. */
        __VERIFIER_assert(6 * sum == (long long)i * (i + 1) * (2 * i + 1));

        if (i >= n) {
            break;
        }
        i++;
    }

    /* Final check: the closed-form holds at the end */

    return 0;
}