#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }
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

// Compute the Greatest Common Divisor (GCD) of two numbers using the Euclidean algorithm
int main() {
    int a, b, temp;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Assume both numbers are positive
    assume_abort_if_not(a > 0 && b > 0);

    if (a < b) {
        // Swap a and b if a is less than b
        temp = a;
        a = b;
        b = temp;
    }

    while (b != 0) {
        temp = b;
        b = a % b; // Find the remainder
        a = temp;
        __VERIFIER_assert(a > 0); // Ensure GCD is always positive
    }

    // By the end of the loop, 'a' is the GCD
    __VERIFIER_assert(a > 0); // Check the computed GCD is greater than 0
    printf("GCD is: %d\n", a);

    return 0;
}