/* Program to calculate the greatest common divisor (GCD)
   using Euclid's algorithm iteratively with verification
   */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "euclid_gcd.c", 6, "reach_error"); }
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
    int a, b, gcd;

    // Non-deterministic values for testing
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Assume a and b are positive integers
    assume_abort_if_not(a > 0);
    assume_abort_if_not(b > 0);

    // Implementing Euclid's algorithm
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    gcd = a;

    // Check if the gcd divides the original numbers (basic correctness check)
    __VERIFIER_assert(gcd != 0); // GCD should never be zero if both inputs are positive
    __VERIFIER_assert(a % gcd == 0);

    return 0;
}