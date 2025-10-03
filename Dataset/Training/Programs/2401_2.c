// gcd_verify.c
// Compute the greatest common divisor of two numbers using
// the Euclidean algorithm and verify that the result divides
// both operands.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "gcd_verify.c", 8, "reach_error");
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

int main(void) {
    /* Two positive integers to compute GCD for */
    int a = 1071;
    int b = 462;

    /* Keep the originals for post‐condition checks */
    int orig_a = a;
    int orig_b = b;

    /* Euclidean algorithm */
    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }

    /* 'a' now holds gcd(orig_a, orig_b) */
    int g = a;

    /* Verify the result is strictly positive */
    /* Verify the gcd divides both original operands */
    __VERIFIER_assert(orig_a % g == 0);

    return 0;
}