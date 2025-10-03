// Division and Remainder by Repeated Subtraction
// Can be analyzed by automated verification tools

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "divmod.c", 5, "reach_error");
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

extern int __VERIFIER_nondet_int(void);

// Compute quotient and remainder of non-negative dividend by positive divisor
// using repeated subtraction.
void divmod_sub(int dividend, int divisor, int *quotient, int *remainder) {
    int q = 0;
    int r = dividend;
    // Loop: subtract divisor until remainder < divisor
    while (r >= divisor) {
        r = r - divisor;
        q = q + 1;
    }
    *quotient = q;
    *remainder = r;
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    // Only consider non-negative dividend and positive divisor
    if (a < 0 || b <= 0) {
        return 0;
    }
    int q, r;
    int a0 = a;
    int b0 = b;
    // Perform division by repeated subtraction
    divmod_sub(a, b, &q, &r);
    // Check correctness: a = q * b + r, and 0 <= r < b
    __VERIFIER_assert(r >= 0 && r < b0);
    return 0;
}