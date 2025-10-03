// Compute the 2-adic valuation v₂(n): the exponent of the highest power of 2 dividing n
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "v2adic.c", 7, "reach_error");
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
    return;
}

int main() {
    int n = __VERIFIER_nondet_int();
    /* we only consider positive inputs up to 1024 to avoid overflow of powers of 2 */
    assume_abort_if_not(n > 0 && n <= 1024);

    long long n0 = n;   // remember original n
    int k = 0;          // the exponent v₂(n)
    long long pow2 = 1; // will hold 2^k

    while (n % 2 == 0) {
        n = n / 2;
        k = k + 1;
        pow2 = pow2 * 2;
    }

    /* At the end:
       - n0 should equal (n * 2^k)
       - n must now be odd
    */
    __VERIFIER_assert(n % 2 == 1);

    return 0;
}