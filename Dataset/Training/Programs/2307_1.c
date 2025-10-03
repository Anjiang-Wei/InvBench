// Geometric Series Verification
// Computes x = sum_{i=0..n} r^i and checks the closed‐form relation
//    (r - 1) * x + 1 == r^(n+1)

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "geo_series.c", 10, "reach_error");
}
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
extern int __VERIFIER_nondet_int(void);

int main() {
    int r, n;
    unsigned long long x, p;
    int i;

    // Non-deterministic inputs with bounds
    r = __VERIFIER_nondet_int();
    assume_abort_if_not(r >= 2 && r <= 10);
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10);

    // Initialize sum and power
    x = 1ULL; // sum_{i=0..0} r^i = 1
    p = 1ULL; // r^0 = 1

    // Compute the series: for i=1..n, add r^i to x
    for (i = 1; i <= n; i++) {
        p = p * (unsigned long long)r;
        x = x + p;
    }

    // Verify the closed-form relation:
    //   (r - 1) * x + 1 == r^(n+1)
    unsigned long long lhs = (unsigned long long)(r - 1) * x + 1ULL;
    unsigned long long rhs = p * (unsigned long long)r;
    __VERIFIER_assert(lhs == rhs);

    return 0;
}