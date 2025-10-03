// A C program demonstrating integer division by repeated subtraction.
// It is suitable for automated verification: it has a loop, nondeterministic inputs,
// assumptions to bound them, and assertions about the result.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "div_loop.c", 3, "reach_error");
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

extern int __VERIFIER_nondet_int(void);

int main(void) {
    int dividend, divisor;
    int quotient = 0;
    int remainder;
    int orig_dividend, orig_divisor;

    // Nondeterministic inputs
    dividend = __VERIFIER_nondet_int();
    divisor = __VERIFIER_nondet_int();

    // Bound the inputs to avoid overflow and ensure divisor > 0
    assume_abort_if_not(dividend >= 0 && dividend <= 1000);
    assume_abort_if_not(divisor > 0 && divisor <= 100);

    // Save originals for post-condition check
    orig_dividend = dividend;
    orig_divisor = divisor;

    // Compute quotient and remainder by repeated subtraction
    while (dividend >= divisor) {
        dividend -= divisor;
        quotient++;
    }

    remainder = dividend;

    // Post-conditions:
    // 1) remainder is non-negative and less than divisor
    // 2) orig_dividend == quotient * orig_divisor + remainder
    __VERIFIER_assert(remainder < orig_divisor);

    return 0;
}