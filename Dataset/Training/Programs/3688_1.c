/*
  Euclidean Algorithm for GCD
  Computes the greatest common divisor of two integers using the subtraction-based form.
  This version is set up for analysis by formal verification tools without explicit loop invariants.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "gcd.c", 8, "reach_error"); }
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
    int a, b;
    int gcd, tmp;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    assume_abort_if_not(a > 0);
    assume_abort_if_not(b > 0);

    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }

    gcd = a; // At this point, 'a' and 'b' should be equal, which is the GCD.
    // The expected post-condition is that gcd divides the original numbers
    __VERIFIER_assert(a % gcd == 0 && b % gcd == 0);

    return 0;
}