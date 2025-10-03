#include <assert.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "complexity.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 100);

    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0 && b >= 0);

    int sum1 = 0;
    int sum2 = 0;

    for (int i = 0; i < n; ++i) {
        sum1 += a;
    }

    for (int i = 0; i < n; ++i) {
        sum2 += b;
    }

    __VERIFIER_assert(sum2 <= n * b);

    if (a < b) {
    } else if (a > b) {
    } else {
    }

    return 0;
}