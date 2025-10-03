#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }

extern unsigned __VERIFIER_nondet_uint(void);

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
    unsigned a, b, c;
    a = __VERIFIER_nondet_uint();
    assume_abort_if_not(a >= 1 && a <= 1000);
    b = __VERIFIER_nondet_uint();
    assume_abort_if_not(b >= 1 && b <= 1000);
    c = __VERIFIER_nondet_uint();
    assume_abort_if_not(c >= 1 && c <= 1000);

    unsigned max_value = a;
    if (b > max_value) {
        max_value = b;
    }
    if (c > max_value) {
        max_value = c;
    }

    unsigned gcd = 1;
    for (unsigned i = 1; i <= max_value; i++) {
        if (a % i == 0 && b % i == 0 && c % i == 0) {
            gcd = i;
        }
    }

    __VERIFIER_assert(a % gcd == 0 && b % gcd == 0 && c % gcd == 0);

    return 0;
}