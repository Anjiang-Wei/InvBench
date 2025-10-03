#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom-ll.c", 8, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int a, b, c;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    c = __VERIFIER_nondet_int();

    assume_abort_if_not(a > 0 && b > 0 && c > 0); // Ensure positive integers

    int x = 0;
    int sum = 0;

    while (x < 10) {
        sum += a + b + c;
        x++;
    }

    // Verify that sum equals 10 times the sum of a, b, and c
    __VERIFIER_assert(sum == 10 * (a + b + c));
    printf("Computation successful: Sum = %d\n", sum);

    return 0;
}