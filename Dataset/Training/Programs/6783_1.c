// New C program example following given patterns

#include <stddef.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 6, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

#define MAX 12 // To keep the factorial within the range of `int`

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= MAX);

    long long factorial = 1;
    int i;

    for (i = 1; i <= n; i++) {
        factorial = factorial * i;
    }

    // Simple check to see if the factorial is greater than zero, which is always true for n >= 0
    __VERIFIER_assert(factorial > 0);

    return 0;
}