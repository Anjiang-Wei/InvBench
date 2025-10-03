/* Program to find the greatest common divisor (GCD) using the Euclidean algorithm */

#include <stdio.h>

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
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b >= 0);
    assume_abort_if_not(a <= 10 && b <= 10);

    // Euclidean algorithm to compute gcd
    int temp;
    while (b != 0) {
        __VERIFIER_assert(a >= 0 && b >= 0); // Basic property of GCD
        temp = b;
        b = a % b;
        a = temp;
    }

    // Result is stored in 'a'

    printf("GCD is %d\n", a);
    return 0;
}