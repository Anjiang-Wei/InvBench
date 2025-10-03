/*
  Algorithm for finding the greatest common divisor (GCD) using the Euclidean algorithm.
  This program includes conditions and loops, and can be analyzed by verification tools.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "gcd-euclidean.c", 5, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int a, b, r, gcd;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Assume initial conditions
    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b >= 0);

    // Make sure neither a nor b is zero simultaneously
    assume_abort_if_not(a > 0 || b > 0);

    // Euclidean Algorithm
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }

    gcd = a;

    // Post-condition check
    __VERIFIER_assert(gcd > 0); // GCD should be positive given assumptions

    // Verify that the gcd divides the original numbers
    __VERIFIER_assert(a % gcd == 0);

    return 0;
}