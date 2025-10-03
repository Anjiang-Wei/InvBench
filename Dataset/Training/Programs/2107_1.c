#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int __VERIFIER_nondet_int();

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    // Pre-condition: a and b must be greater than zero for meaningful results
    if (!(a > 0 && b > 0)) {
        return 0;
    }

    int gcd = 1;
    int min = (a < b) ? a : b;

    for (int i = 1; i <= min; ++i) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }

    // Checking if the computed gcd divides both a and b
    __VERIFIER_assert(a % gcd == 0 && b % gcd == 0);
    printf("GCD of %d and %d is %d\n", a, b, gcd);

    return 0;
}