/*
  Binary exponentiation verifier
  Computes result = x^n using the binary exponentiation method
  and checks it against a straightforward multiplication loop.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "binexp_verifier.c", 9, "reach_error");
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
    /* nondeterministic inputs */
    int x = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();

    /* restrict ranges so multiplication won't overflow 64-bit */
    assume_abort_if_not(x >= 0 && x <= 5);
    assume_abort_if_not(n >= 0 && n <= 5);

    /* binary exponentiation */
    long long result = 1;
    long long base = x;
    int exp = n;

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = result * base;
        }
        base = base * base;
        exp = exp / 2;
    }

    /* straightforward check by repeated multiplication */
    long long expected = 1;
    for (int i = 0; i < n; i++) {
        expected = expected * x;
    }

    /* final assertion: both methods yield the same power */
    __VERIFIER_assert(result == expected);

    return 0;
}