#include <stdio.h>

extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 5, "reach_error"); }
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

extern unsigned __VERIFIER_nondet_uint(void);

int main() {
    unsigned a = __VERIFIER_nondet_uint(); // Get a non-deterministic unsigned integer
    unsigned b = __VERIFIER_nondet_uint(); // Get another non-deterministic unsigned integer
    unsigned sum = 0;
    unsigned diff = 0;

    assume_abort_if_not(a >= 1 && a <= 50000);
    assume_abort_if_not(b >= 1 && b <= 50000);

    // Ensure sum is the sum of a and b
    unsigned x = a;
    unsigned y = b;

    // Loop to calculate the sum
    for (int i = 0; i < 10; ++i) {
        sum += x;
        sum += y;
    }

    // Another loop to calculate the difference
    int counter = 0;
    while (x != y && counter++ < 10) {
        if (x > y) {
            x = x - y;
        } else {
            y = y - x;
        }
    }

    diff = x; // x (or y) would be the gcd of the original x and y

    // Verify some properties
    __VERIFIER_assert(sum == (a + b) * 10);

    return 0;
}