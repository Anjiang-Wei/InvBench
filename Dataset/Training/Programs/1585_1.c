// Compute integer square root: find r = floor(sqrt(n)) for a nondeterministic n

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "int_sqrt.c", 8, "reach_error"); }

extern unsigned __VERIFIER_nondet_uint(void);

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
    unsigned n = __VERIFIER_nondet_uint();
    /* restrict n to a reasonable bound so that (r+1)^2 won't overflow */
    assume_abort_if_not(n <= 10000);

    unsigned r = 0;

    /* loop to find the largest r such that (r+1)^2 > n */
    while ((r + 1) * (r + 1) <= n) {
        r++;
    }

    /* postcondition: r*r <= n < (r+1)*(r+1) */
    __VERIFIER_assert(r * r <= n && (r + 1) * (r + 1) > n);

    return 0;
}