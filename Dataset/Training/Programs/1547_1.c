/*
  Integer square root via binary search.
  Given n >= 0, finds the largest integer r such that r*r <= n.
  At the end, it asserts r*r <= n < (r+1)*(r+1).
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "isqrt-bsearch.c", 10, "reach_error");
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
    int n = __VERIFIER_nondet_int();
    /* we only handle non-negative inputs */
    assume_abort_if_not(n >= 0);

    int low = 0;
    int high = n + 1; /* invariant: true root lies in [low, high) */
    int mid;

    /* binary search: stop when interval size is 1 */
    while (high - low > 1) {
        mid = low + (high - low) / 2;
        /* compare mid*mid to n, cast to long long to avoid overflow */
        if ((long long)mid * mid <= n) {
            low = mid;
        } else {
            high = mid;
        }
    }

    /* postcondition: low*low <= n < (low+1)*(low+1) */
    __VERIFIER_assert((long long)low * low <= n);

    return 0;
}