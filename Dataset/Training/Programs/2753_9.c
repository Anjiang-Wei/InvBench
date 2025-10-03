// Complete C program with multiple loop-based computations and verification assertions.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "combined_seq_verif.c", 4, "reach_error");
}

extern short __VERIFIER_nondet_short(void);

/* Abort if the condition is false */
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

/* Verification assertion: reach error if cond is false */
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    /* We will perform three separate sequence computations:
       1) Sum of squares: S2(n) = sum_{i=1..n} i^2 = n(n+1)(2n+1)/6
       2) Sum of cubes:   S3(n) = sum_{i=1..n} i^3 = [n(n+1)/2]^2
       3) Sum of triangular numbers:
                         T(i) = sum_{j=1..i} j = i(i+1)/2
                         S_T(n) = sum_{i=1..n} T(i) = n(n+1)(n+2)/6
    */

    /* 1) Sum of squares computation */
    short k1 = __VERIFIER_nondet_short();
    /* limit n to a small non-negative range for verification */
    assume_abort_if_not(k1 >= 0 && k1 <= 20);

    long long c1 = 0;
    long long sum_sq = 0; /* will accumulate i^2 */

    /* Before entering the loop, the sum is correct for c1 = 0 */

    while (1) {
        /* Check the polynomial relation:
           6 * sum_sq == c1 * (c1 + 1) * (2*c1 + 1)
        */

        if (!(c1 < k1)) {
            break;
        }

        c1 = c1 + 1;
        sum_sq = sum_sq + (c1 * c1);
    }

    /* Final check after the loop */

    /* 2) Sum of cubes computation */
    short k2 = __VERIFIER_nondet_short();
    assume_abort_if_not(k2 >= 0 && k2 <= 20);

    long long c2 = 0;
    long long sum_cu = 0;  /* will accumulate i^3 */
    long long sum_lin = 0; /* will accumulate i = sum of first c2 integers */

    /* Initial state: both sums are zero */

    while (1) {
        /* Check the relation:
           sum_cu == sum_lin * sum_lin
        */

        if (!(c2 < k2)) {
            break;
        }

        c2 = c2 + 1;
        sum_lin = sum_lin + c2;
        sum_cu = sum_cu + (c2 * c2 * c2);
    }

    /* Final check */

    /* 3) Sum of triangular numbers computation */
    short k3 = __VERIFIER_nondet_short();
    assume_abort_if_not(k3 >= 0 && k3 <= 20);

    long long c3 = 0;
    long long tri_acc = 0; /* T(c3) = sum_{j=1..c3} j */
    long long sum_tri = 0; /* sum of triangular numbers up to c3 */

    /* Initial state: c3=0 => tri_acc=0, sum_tri=0 */

    while (1) {
        /* Check the polynomial invariant:
           6 * sum_tri == c3 * (c3 + 1) * (c3 + 2)
        */

        if (!(c3 < k3)) {
            break;
        }

        c3 = c3 + 1;
        tri_acc = tri_acc + c3;
        sum_tri = sum_tri + tri_acc;
    }

    /* Final assertion after loop exit */
    __VERIFIER_assert(6 * sum_tri == c3 * (c3 + 1) * (c3 + 2));

    /* Program completed all verifiable computations */
    return 0;
}