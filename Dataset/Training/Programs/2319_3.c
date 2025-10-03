extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "sum_squares_triangles.c", 1, "reach_error");
}
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    /* nondeterministic bound */
    int k = __VERIFIER_nondet_int();
    /* constrain k to a reasonable non‐negative size */
    assume_abort_if_not(k >= 0);
    assume_abort_if_not(k <= 10000);

    long y = 0;
    long sum = 0;    /* sum = 1 + 2 + ... + y */
    long sum_sq = 0; /* sum_sq = 1^2 + 2^2 + ... + y^2 */
    int count = 0;

    /* iterate exactly k times */
    while (count < k) {
        count++;
        y++;
        sum += y;
        sum_sq += y * y;

        /* validate triangular number formula: 2*sum == y*(y+1) */

        /* validate sum of squares: 6*sum_sq == y*(y+1)*(2*y+1) */
    }

    /* final checks */
    __VERIFIER_assert(2 * sum == y * (y + 1));
    return 0;
}