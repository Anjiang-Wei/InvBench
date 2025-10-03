// Integer square root via binary search with post-condition verification

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "isqrt.c", 10, "reach_error"); }

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

#define MAX_N 1000000U

int main(void) {
    unsigned int N = __VERIFIER_nondet_uint();
    assume_abort_if_not(N <= MAX_N);

    unsigned long long lo = 0;
    unsigned long long hi = (unsigned long long)N + 1;
    unsigned long long mid;

    while (lo + 1ULL < hi) {
        mid = lo + (hi - lo) / 2ULL;
        if (mid * mid <= N) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    // Post-conditions: lo*lo <= N < hi*hi, and hi == lo+1
    __VERIFIER_assert(lo * lo <= N);

    return 0;
}