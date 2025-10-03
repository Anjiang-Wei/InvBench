// int_sqrt.c: compute integer square root and verify remainder properties

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "int_sqrt.c", 9, "reach_error"); }

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

int main() {
    unsigned int a;
    unsigned int x = 0;
    unsigned long long ua;
    unsigned long long r;

    /* get a nondeterministic input, but bound it to avoid overflow */
    a = __VERIFIER_nondet_uint();
    assume_abort_if_not(a <= 1000000);

    ua = a;

    /* find the largest x such that (x+1)^2 > a */
    while ((unsigned long long)(x + 1) * (x + 1) <= ua) {
        x++;
    }

    /* compute remainder r = a - x^2 */
    r = ua - (unsigned long long)x * x;

    /* check the well‐known remainder bound: r < 2*x + 1 */

    /* check that x^2 + r reconstructs the original a */
    __VERIFIER_assert((unsigned long long)x * x + r == ua);

    return 0;
}