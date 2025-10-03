// Compute the largest power of two not exceeding n,
// and its exponent k, so that x = 2^k, x <= n < 2*x.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "pow2.c", 9, "reach_error");
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

int main() {
    int n;
    int x, k;

    // nondeterministic input
    n = __VERIFIER_nondet_int();
    // bound n to a reasonable positive range for verification
    assume_abort_if_not(n >= 1 && n <= 1024);

    // initialize
    x = 1; // current power of two
    k = 0; // exponent

    // grow x until doubling would exceed n
    while (x * 2 <= n) {
        x = x * 2;
        k = k + 1;
    }

    // post-conditions: x is the largest power of two <= n
    __VERIFIER_assert(x <= n && n < x * 2);
    // and indeed x equals 2^k

    return 0;
}