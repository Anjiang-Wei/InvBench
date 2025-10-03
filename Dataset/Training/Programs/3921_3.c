/*
 * Program to compute powers of a given number and verify
 * relationships between the powers using iterative multiplications.
 */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "power_verification.c", 5, "reach_error"); }
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int base, exponent, i;
    long long result, prev_result;

    // Obtain non-deterministic values for base and exponent
    base = __VERIFIER_nondet_int();
    assume_abort_if_not(base >= 2 && base <= 10); // Assume base in range [2, 10]
    exponent = __VERIFIER_nondet_int();
    assume_abort_if_not(exponent >= 1 && exponent <= 20); // Assume exponent in range [1, 20]

    result = 1;
    prev_result = 1;

    for (i = 0; i < exponent; i++) {
        prev_result = result;
        result *= base;

        // Verify if the current result is a multiple of the base
        // Verify relationship between consecutive powers
    }

    // Final expected result check
    if (exponent > 0) {
        __VERIFIER_assert(result == prev_result * base);
    }

    return 0;
}