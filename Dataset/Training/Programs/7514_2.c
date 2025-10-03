#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sequence.c", 8, "reach_error"); }
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
    int n, a, b, c;
    long long sum, term;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 10);

    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && a <= 5);
    b = __VERIFIER_nondet_int();
    assume_abort_if_not(b >= 0 && b <= 5);

    sum = a + b;
    term = a;

    c = 0;
    while (c < n) {

        c++;
        term = term * 2 + c;
        sum = sum + term;
    }

    // Property: sum should be greater than n * a at the end
    __VERIFIER_assert(sum > n * a);

    return 0;
}