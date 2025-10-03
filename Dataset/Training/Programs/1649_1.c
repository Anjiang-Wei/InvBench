/*
  Program to find the greatest common divisor (GCD) using Euclid's algorithm
  Introduces nondeterministic values for a and b
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "gcd-ll.c", 8, "reach_error"); }
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
    int temp;

    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && a <= 10);
    b = __VERIFIER_nondet_int();
    assume_abort_if_not(b >= 0 && b <= 10);

    assume_abort_if_not(b >= 1 || a >= 1); // at least one should be non-zero

    // Ensure a >= b, if not, swap
    if (a < b) {
        temp = a;
        a = b;
        b = temp;
    }

    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;

        __VERIFIER_assert(a >= 0 && b >= 0);
    }

    // Now a holds the gcd

    return 0;
}