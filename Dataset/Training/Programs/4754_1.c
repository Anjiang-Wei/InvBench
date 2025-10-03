#include <stdio.h>
#include <stdlib.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
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

int counter = 0;

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int a, b, c, sum, gcd_value;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    assume_abort_if_not(a > 0);
    assume_abort_if_not(b > 0);

    c = 0;
    sum = 0;

    while (counter++ < 50) {
        c += 3;
        sum += (a + b + c);

        if (c > a * b) {
            break;
        }
    }

    gcd_value = gcd(a, b);
    __VERIFIER_assert(gcd_value > 0); // GCD should always be positive

    printf("Sum: %d\n", sum);
    printf("GCD of %d and %d is: %d\n", a, b, gcd_value);

    // Verifying the relationship between `sum`, `a`, `b`, and `c`
}