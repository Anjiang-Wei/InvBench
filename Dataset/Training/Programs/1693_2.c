#include <stdlib.h>

/* Euclidean Algorithm to find GCD with additional calculation constraints */
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
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
    int a, b;
    int gcd, swap_helper;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 1 && a <= 100);
    assume_abort_if_not(b >= 1 && b <= 100);

    if (a < b) {
        swap_helper = a;
        a = b;
        b = swap_helper;
    }

    gcd = b;

    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;

        // Constraint condition verification: gcd should not exceed the max of the two numbers
    }

    // Final gcd found in a
    __VERIFIER_assert(a >= 1); // Additional constraint to ensure the GCD is a valid non-zero number

    return 0;
}