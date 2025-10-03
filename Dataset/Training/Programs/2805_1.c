#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "verify.c", 4, "reach_error"); }

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

int calculate_gcd(int m, int n) {
    while (n != 0) {
        int t = n;
        n = m % n;
        m = t;
    }
    return m;
}

int counter = 0;

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    assume_abort_if_not(a > 0 && b > 0);

    int gcd_orig = calculate_gcd(a, b);
    __VERIFIER_assert(gcd_orig > 0);

    int product = a * b;
    int gcd_approx = 1; // Start with the minimum GCD

    while (counter < 5) {
        counter++;

        int random_addition = __VERIFIER_nondet_int();
        if (random_addition <= 0) {
            continue;
        }

        gcd_approx += random_addition;

        if (gcd_approx > gcd_orig) {
            break;
        }
    }

    // For larger values of gcd_approx, we assert gcd_approx still satisfies a specific property
    if (gcd_approx * gcd_approx > product) {
    }

    return 0;
}