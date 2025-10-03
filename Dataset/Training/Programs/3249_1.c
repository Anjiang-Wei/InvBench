#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "example_new.c", 7, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
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
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int x, y, g, i, sum;

    x = __VERIFIER_nondet_int();
    assume_abort_if_not(x > 0 && x <= 100);
    y = __VERIFIER_nondet_int();
    assume_abort_if_not(y > 0 && y <= 100);

    g = gcd(x, y);

    // Simple loop with a calculation
    sum = 0;
    for (i = 1; i <= 10; i++) {
        sum += i * g;
    }

    // Verification: sum should be equal to the expected arithmetic series multiplied by gcd
    __VERIFIER_assert(sum == g * (10 * 11) / 2);

    // Print result
    printf("GCD of %d and %d is %d\n", x, y, g);
    printf("Sum of series: %d\n", sum);

    return 0;
}