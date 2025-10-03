#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom.c", 3, "reach_error"); }

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
    int n = __VERIFIER_nondet_int();
    int sum = 0;
    int product = 1;
    int i = 1;

    assume_abort_if_not(n > 0 && n < 1000);

    while (i <= n) {
        sum += i;
        product *= i;

        __VERIFIER_assert(sum >= i);

        if (i == n) {
            break;
        }

        i++;
    }
}