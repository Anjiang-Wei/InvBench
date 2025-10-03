#include <limits.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fact-ll.c", 5, "reach_error"); }
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
    int n;
    long long factor, result, i;

    n = __VERIFIER_nondet_int();            // Arbitrary input value from external environment
    assume_abort_if_not(n >= 0 && n <= 12); // Ensure n! does not exceed INT_MAX for simplicity

    factor = 1;
    result = 1;

    for (i = 1; i <= n; i++) {
    }

    __VERIFIER_assert(result == factor);

    printf("Factorial of %d is %lld\n", n, result);
    return 0;
}