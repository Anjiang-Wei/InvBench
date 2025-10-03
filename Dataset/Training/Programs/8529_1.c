#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// Calculate factorial iteratively and validate using an invariant

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial-inv.c", 5, "reach_error"); }
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

int counter = 0;
int main() {
    int n;
    long long factorial, i;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0);

    factorial = 1;
    i = 1;

    // Consistent validation pattern without explicit invariant assertions
    while (counter++ < 100) {
        if (!(i <= n)) {
            break;
        }

        factorial = factorial * i;
        i = i + 1;
    }

    // Check if factorial of n ends > 0 for n >= 0
    __VERIFIER_assert(factorial > 0 || n == 0);

    printf("The factorial of %d is %lld\n", n, factorial);
    return 0;
}