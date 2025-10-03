/* Binary search over a small sorted array for verification */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "binary_search_verifier.c", 5, "reach_error");
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
    /* choose array length */
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 10);

    /* build a sorted array a[i] = 2*i */
    int a[10];
    for (int i = 0; i < n; i++) {
        a[i] = 2 * i;
    }

    /* choose a target value within the array's possible range */
    int v = __VERIFIER_nondet_int();
    assume_abort_if_not(v >= 0 && v <= 2 * (n - 1));

    /* binary search */
    int lo = 0, hi = n - 1, mid;
    int found = -1;
    while (lo <= hi) {
        mid = lo + (hi - lo) / 2;
        if (a[mid] < v) {
            lo = mid + 1;
        } else if (a[mid] > v) {
            hi = mid - 1;
        } else {
            found = mid;
            break;
        }
    }

    /* post‐search checks */
    if (found >= 0) {
        /* if found, the array element must equal v */
        __VERIFIER_assert(a[found] == v);
    } else {
        /* if not found, lo must have crossed hi */
    }

    return 0;
}