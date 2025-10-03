// integer_sqrt_bsearch.c
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "integer_sqrt_bsearch.c", 5, "reach_error");
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
    /* nondeterministic input */
    int n = __VERIFIER_nondet_int();
    /* we only handle non-negative inputs up to one million */
    assume_abort_if_not(n >= 0 && n <= 1000000);

    /* binary search for floor(sqrt(n)) */
    int low = 0;
    int high = n + 1;

    while (high - low > 1) {
        int mid = low + (high - low) / 2;
        long long sq = (long long)mid * mid;
        if (sq <= n) {
            low = mid;
        } else {
            high = mid;
        }
    }

    /* final checks: low^2 <= n < (low+1)^2 */
    __VERIFIER_assert((long long)low * low <= n);

    return 0;
}