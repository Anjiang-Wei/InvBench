extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "sum_squares.c", 1, "reach_error");
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
    int k;
    long long x;
    int c;

    /* nondeterministically choose k and bound it */
    k = __VERIFIER_nondet_int();
    assume_abort_if_not(k >= 0 && k <= 1000);

    /* x will accumulate the sum of squares 1^2 + 2^2 + ... + c^2 */
    x = 0;
    c = 0;

    while (1) {
        /* Check the known closed‐form:
             sum_{i=1..c} i^2 = c*(c+1)*(2*c+1)/6
           multiply both sides by 6: 6*x == c*(c+1)*(2*c+1)
        */
        __VERIFIER_assert(6 * x == (long long)c * (c + 1) * (2 * c + 1));

        if (!(c < k)) {
            break;
        }

        c = c + 1;
        x = x + (long long)c * c;
    }

    /* Final check for c == k */

    return 0;
}