#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
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

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n < 100);

    int sum = 0;
    int product = 1;
    int i;

    for (i = 1; i <= n; i++) {
        sum += i;
        product *= i;

        // Assert that the sum of the first i natural numbers is equal to i*(i+1)/2
        __VERIFIER_assert(sum == (i * (i + 1)) / 2);
    }

    // Assert that the product of numbers is positive

    return 0;
}