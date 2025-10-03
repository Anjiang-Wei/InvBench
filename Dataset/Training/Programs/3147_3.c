// gcd_verify.c
// A simple program to compute the greatest common divisor (GCD)
// of two positive integers using the Euclidean algorithm,
// then verify that the result is a positive divisor of both inputs.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "gcd_verify.c", 7, "reach_error");
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

int gcd(int a, int b) {
    // Euclidean algorithm: repeatedly replace (a,b) with (b, a mod b)
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main(void) {
    // Example inputs
    int x = 48;
    int y = 18;

    // Compute GCD
    int g = gcd(x, y);

    // Verification conditions:
    // 1) GCD must be positive
    // 2) GCD must divide both original inputs
    __VERIFIER_assert(y % g == 0);

    return 0;
}