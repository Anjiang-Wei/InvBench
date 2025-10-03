/* Program to compute powers of a natural number iteratively */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "power.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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
    return;
}

int main() {
    int base, exponent, result, i;

    // Get non-deterministic input
    base = __VERIFIER_nondet_int();
    exponent = __VERIFIER_nondet_int();

    // Assume conditions for validity
    assume_abort_if_not(base >= 0 && base <= 10);
    assume_abort_if_not(exponent >= 0 && exponent <= 5);

    // Initialize variables
    result = 1; // Identity for multiplication
    i = 0;      // Iterator

    // Compute base to the power of exponent iteratively
    while (i < exponent) {
        result *= base;
        i++;
    }

    // Verify some basic properties of powers
    // If exponent is zero, the result should be 1 (assuming base is not 0)
    if (exponent == 0) {
    } else {
        __VERIFIER_assert(result >= base); // Result should at least be base itself if non-zero
    }

    return 0;
}