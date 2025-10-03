// Compute the largest power of two not exceeding a positive integer n:
// That is, find p and pow2 such that pow2 = 2^p and pow2 ≤ n < 2·pow2.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "pow2_log2.c", 10, "reach_error");
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
    int n = __VERIFIER_nondet_int();
    // We restrict n to the range [1, 2^30] so that the loop terminates safely
    assume_abort_if_not(n >= 1);
    assume_abort_if_not(n <= (1 << 30));

    int p = 0;
    long long pow2 = 1;

    // Build up pow2 = 2^p until doubling would exceed n.
    // The counter bound (<= 31) ensures termination for verification tools.
    while (counter++ < 31 && pow2 * 2 <= n) {
        pow2 = pow2 * 2;
        p = p + 1;
    }

    // Post-conditions: pow2 is the largest power of two ≤ n,
    // and p is its exponent.
    __VERIFIER_assert(pow2 * 2 > n);

    return 0;
}