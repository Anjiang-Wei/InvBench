#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 12, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
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
    return;
}

int main() {
    int x, i;
    long long fact;

    x = __VERIFIER_nondet_int();
    assume_abort_if_not(x >= 0 && x <= 20); // Only consider factorials up to 20!

    fact = 1;
    i = 1;

    while (i <= x) {
        fact = fact * i;
        i = i + 1;
    }

    // Verify that the computed factorial is not zero
    __VERIFIER_assert(fact > 0);

    return 0;
}