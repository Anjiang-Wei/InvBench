extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "gcd_lcm_verify.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

void avoid_zero(int v) {
    if (v == 0) {
        abort();
    }
}

int main() {
    /* Choose two non‐zero positive integers */
    int a = 120;
    int b = 35;
    int orig_a = a;
    int orig_b = b;

    /* Ensure we never divide or mod by zero */
    avoid_zero(b);

    /* Compute gcd(a,b) by Euclid's algorithm */
    int x = a;
    int y = b;
    while (y != 0) {
        int t = x % y;
        x = y;
        y = t;
    }
    int gcd = x;
    avoid_zero(gcd);

    /* Compute lcm(a,b) = (a / gcd) * b */
    long long lcm = (long long)(orig_a / gcd) * orig_b;
    long long prod = (long long)orig_a * orig_b;

    /* Verify the well‐known relation gcd * lcm == a * b */
    __VERIFIER_assert(gcd * lcm == prod);

    return 0;
}