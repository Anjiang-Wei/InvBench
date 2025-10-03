/*
Arithmetic Series
computes x = a * sum(1..n), y = a * n
ensures y + x == a * n * (n + 1) / 2
*/

#include <stdbool.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "arith.c", 9, "reach_error"); }
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

int main() {
    int a, n;
    long long x, y, c;

    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 1 && a <= 10);
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 10);

    x = 0;
    y = a * n;
    c = 1;

    while (1) {
        __VERIFIER_assert(y + x == a * (c - 1) * c / 2 + a * n);

        if (!(c <= n)) {
            break;
        }

        x = x + a * c;
        c = c + 1;
    }

    printf("Success: y + x = %lld, expected = %d\n", y + x, a * n * (n + 1) / 2);
    return 0;
}