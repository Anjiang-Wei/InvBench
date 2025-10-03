#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_prog.c", 3, "reach_error"); }
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
    int x, y, n;
    long long factorial = 1;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0);
    assume_abort_if_not(n <= 10);

    x = 0;
    y = 1;

    while (x < n) {
        y = y + x;
        x = x + 1;

        if (x <= n) {
            factorial = factorial * x;
        }
    }

    __VERIFIER_assert(factorial > 0);

    printf("Factorial of %d is %lld\n", n, factorial);
    printf("Final value of y: %d\n", y);

    return 0;
}