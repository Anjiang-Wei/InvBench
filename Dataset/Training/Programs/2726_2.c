#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 7, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0 && b >= 0); // Start with non-negative integers

    int gcd = 0; // Track GCD computation
    int x = a;
    int y = b;

    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }

    gcd = x; // GCD is held in x after the loop ends

    // To be a valid gcd, gcd should divide both a and b

    // Additionally, if either a or b is zero, gcd should be the other number
    if (a == 0 || b == 0) {
        __VERIFIER_assert(gcd == a + b);
    }

    return 0;
}