#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_example.c", 5, "reach_error"); }
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

int counter = 0;

int main() {
    int a, b, gcd;
    a = abs(__VERIFIER_nondet_int());
    b = abs(__VERIFIER_nondet_int());
    assume_abort_if_not(a >= 1);
    assume_abort_if_not(b >= 1);

    // The loop follows the Euclidean algorithm for finding the GCD
    int x = a;
    int y = b;

    while (counter++ < 100) { // Ensure termination for bounded analysis
        if (y == 0) {
            break;
        }
        int temp = y;
        y = x % y;
        x = temp;
    }

    gcd = x;
    __VERIFIER_assert(gcd > 0); // GCD should always be greater than 0 for positive inputs

    printf("GCD(%d, %d) = %d\n", a, b, gcd);
    return 0;
}