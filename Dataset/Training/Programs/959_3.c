// sum_squares.c
// Computes the sum of squares 1^2 + 2^2 + ... + n^2
// and checks the closed‐form formula via verification asserts.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "sum_squares.c", 6, "reach_error");
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

int counter = 0;

int main() {
    int n;
    long long sum2 = 0;
    long long prev;
    int i = 1;

    // pick a small n so that automated tools can unroll the loop
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0);
    assume_abort_if_not(n <= 10);

    // sum up squares 1^2 + 2^2 + ... + n^2
    while (counter++ < n) {
        prev = sum2;
        sum2 += (long long)i * i;
        // ensure the sum strictly increases each iteration
        i++;
    }

    // verify the loop ran exactly n times

    // final check: closed‐form formula
    //    1^2 + 2^2 + ... + n^2 == n*(n+1)*(2n+1)/6
    __VERIFIER_assert(6 * sum2 == (long long)n * (n + 1) * (2LL * n + 1));

    return 0;
}