#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int __VERIFIER_nondet_int();
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int m, n;
    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(m > 0);
    assume_abort_if_not(n > 0);

    int gcd = 0;

    for (int i = 1; i <= m && i <= n; i++) {
        if (m % i == 0 && n % i == 0) {
            gcd = i;
        }
    }

    __VERIFIER_assert(gcd > 0);

    printf("GCD of %d and %d is %d\n", m, n, gcd);

    return 0;
}