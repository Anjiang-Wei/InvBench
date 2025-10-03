/* Exponentiation by Squaring Verification */
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "power_sq.c", 8, "reach_error"); }

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
    int x = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();
    /* restrict to small values to avoid overflow */
    assume_abort_if_not(x >= 0 && x <= 5);
    assume_abort_if_not(n >= 0 && n <= 5);

    /* compute result = x^n by exponentiation by squaring */
    int base = x;
    int exp = n;
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = result * base;
        }
        base = base * base;
        exp = exp / 2;
    }

    /* recompute x^n by simple repeated multiplication */
    int check = 1;
    for (int i = 0; i < n; i++) {
        check = check * x;
    }

    /* final consistency check */
    __VERIFIER_assert(result == check);

    return 0;
}