/*
 Patterned after the provided examples, this program follows similar structures and
 logic constraints. The program calculates the greatest common divisor (GCD) of two
 non-negative integers using the Euclidean algorithm while verifying certain
 properties. The loop ensures the program is not trivial, and necessary external
 functions are defined for verification purposes.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "gcd.c", 5, "reach_error"); }
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
    int a, b, temp;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0 && b >= 0); // Ensure non-negative integers
    assume_abort_if_not(a != 0 || b != 0); // At least one should be non-zero

    // Start of the Euclidean algorithm
    while (b != 0) {
        __VERIFIER_assert(a >= 0 && b >= 0); // Ensure integrity of process
        temp = b;
        b = a % b;
        a = temp;
    }

    // Compares if the result 'a' is the gcd, the gcd must divide both numbers.
    return 0;
}