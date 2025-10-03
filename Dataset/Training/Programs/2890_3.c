extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "gcd_lcm_sum.c", 4, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main(void) {
    /* Compute GCD of X0 and Y0 by the subtraction-based Euclidean algorithm */
    unsigned int X0 = 30, Y0 = 18;
    unsigned int a = X0, b = Y0;
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    unsigned int gcd = a;

    /* Compute LCM via the relationship lcm·gcd = X0·Y0 */
    unsigned int lcm = (X0 / gcd) * Y0;

    /* Verify the computed values */

    /* Additional loop: sum of the first 10 positive integers */
    unsigned int sum = 0;
    unsigned int i;
    for (i = 1; i <= 10; ++i) {
        sum += i;
    }
    __VERIFIER_assert(sum == 55);

    /* Verify a simple relation between LCM and this sum */

    return 0;
}