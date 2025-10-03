#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "program.c", 4, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int __VERIFIER_nondet_int();

int main() {
    int n = __VERIFIER_nondet_int();
    int sum = 0;
    int i = 0;

    // Assumption: n should be non-negative for this computation
    if (n < 0) {
        return 0;
    }

    // Loop that computes the sum of even numbers up to n
    while (i <= n) {
        if (i % 2 == 0) {
            sum += i;
        }
        i++;
    }

    // Verify that the result is non-negative
    __VERIFIER_assert(sum >= 0);

    printf("Sum of even numbers up to %d is %d\n", n, sum);

    return 0;
}