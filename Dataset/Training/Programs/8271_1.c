/* Euclidean Algorithm for computing the Greatest Common Divisor (GCD)
   of two natural numbers
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "gcd.c", 5, "reach_error"); }
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
    long long larger, smaller, temp;

    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && a <= 50);
    b = __VERIFIER_nondet_int();
    assume_abort_if_not(b >= 0 && b <= 50);
    assume_abort_if_not(b >= 1); // Ensure b is not zero to prevent division by zero

    // Initialize larger and smaller
    if (a >= b) {
        larger = a;
        smaller = b;
    } else {
        larger = b;
        smaller = a;
    }

    while (1) {
        if (!(smaller != 0)) {
            break;
        }

        temp = larger % smaller;
        larger = smaller;
        smaller = temp;
    }

    __VERIFIER_assert(larger > 0); // GCD is always positive for non-zero natural numbers
    printf("GCD: %lld\n", larger);

    return 0;
}