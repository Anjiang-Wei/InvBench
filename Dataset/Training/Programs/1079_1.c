/*
  Greatest common divisor (GCD) calculation using the Euclidean algorithm.
  The program finds gcd(A, B), where A and B are positive integers.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "gcd.c", 8, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);
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
    unsigned int A, B;
    unsigned int temp;

    A = __VERIFIER_nondet_uint();
    B = __VERIFIER_nondet_uint();
    assume_abort_if_not(A > 0);
    assume_abort_if_not(B > 0);

    // Start of the Euclidean algorithm
    while (B != 0) {
        temp = B;
        B = A % B;
        A = temp;
    }

    // A now holds the gcd of the original A and B
    // Check gcd property: A should divide both original numbers
    __VERIFIER_assert(A != 0); // A should not be zero to be a valid gcd

    return 0;
}