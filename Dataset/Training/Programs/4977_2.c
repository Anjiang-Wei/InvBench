#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_example.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int counter = 0;

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    int sum = 0;

    assume_abort_if_not(x > 0);
    assume_abort_if_not(y > 0);

    // Calculate the sum of integers from 1 to x
    for (int i = 1; i <= x; i++) {
        sum += i;
    }

    // Find greatest common divisor (GCD) of sum and y using Euclid’s algorithm
    int a = sum;
    int b = y;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    int gcd = a;

    // Verify some fundamental properties
    __VERIFIER_assert(sum >= x);

    printf("Sum of integers from 1 to %d = %d\n", x, sum);
    printf("GCD of %d and %d = %d\n", sum, y, gcd);

    return 0;
}