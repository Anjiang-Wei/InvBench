/*
GCD Calculator using the Euclidean Algorithm
Steps:
1. Read two positive integers a and b.
2. Compute gcd(a, b) using a loop.
3. Ensure all intermediate assertions hold.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "gcd.c", 14, "reach_error"); }
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
    unsigned int a, b;

    // Assume two random non-negative integers with value <= 100
    a = __VERIFIER_nondet_uint();
    assume_abort_if_not(a >= 1 && a <= 100);

    b = __VERIFIER_nondet_uint();
    assume_abort_if_not(b >= 1 && b <= 100);

    // Ensure a >= b for simpler processing
    if (b > a) {
        unsigned int temp = a;
        a = b;
        b = temp;
    }

    // Euclidean algorithm loop
    while (b != 0) {
        unsigned int remainder = a % b;
        a = b;
        b = remainder;
    }

    // Verify the result if unique increase of a greater than zero initially
    __VERIFIER_assert(a >= 1);

    // a is now the gcd of the original values
    return 0;
}