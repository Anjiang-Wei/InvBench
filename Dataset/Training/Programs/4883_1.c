/*
  Extended Euclidean Algorithm
  Computes the greatest common divisor (GCD) of two numbers a and b
  and finds coefficients x and y such that a*x + b*y = gcd(a, b)
  Program includes verification using abstract assertion conditions.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "extended_euclid.c", 9, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b >= 0);

    int old_a = a;
    int old_b = b;

    int x0 = 1, x1 = 0;
    int y0 = 0, y1 = 1;

    while (b != 0) {
        int q = a / b;
        int temp;

        temp = a;
        a = b;
        b = temp % b;

        temp = x0;
        x0 = x1;
        x1 = temp - q * x1;

        temp = y0;
        y0 = y1;
        y1 = temp - q * y1;
    }

    // Verify the correctness of the coefficients
    // a*x + b*y = gcd(a, b)
    __VERIFIER_assert(a == old_a * x0 + old_b * y0);

    return 0;
}