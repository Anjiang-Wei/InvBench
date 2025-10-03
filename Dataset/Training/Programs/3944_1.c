#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
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

int main() {
    int m, n;
    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(m > 0 && n > 0);

    int gcd = 1;
    int i = 1;

    while (i <= m && i <= n) {
        // Check if i is a common divisor
        if (m % i == 0 && n % i == 0) {
            gcd = i;
        }
        i = i + 1;
    }

    // Verify the greatest common divisor by a condition
    __VERIFIER_assert(m % gcd == 0 && n % gcd == 0);

    printf("The GCD of %d and %d is %d\n", m, n, gcd);

    return 0;
}