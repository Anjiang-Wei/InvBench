/*
  Euclidean Algorithm for GCD
  Uses the Euclidean algorithm to compute the greatest common divisor (GCD) of two integers.
*/
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "gcd-euclidean.c", 8, "reach_error"); }
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
    int a, b, gcd, temp;

    // Two integers a and b, constrained to positive integers
    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && a <= 1000);
    b = __VERIFIER_nondet_int();
    assume_abort_if_not(b >= 0 && b <= 1000);

    // Ensure both numbers are valid for gcd computation
    assume_abort_if_not(a > 0 || b > 0);

    // Implement the Euclidean algorithm
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }

    gcd = a; // The final value of `a` is the GCD

    // Check if the gcd divides both original numbers, a wider test
    __VERIFIER_assert((a % gcd == 0) && (b % gcd == 0));

    return 0;
}