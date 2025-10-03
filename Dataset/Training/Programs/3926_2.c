#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_verification_ex.c", 6, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR:
        reach_error();
    }
}

int main() {
    int a, b, n;
    long long factorial = 1, sum = 0;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(n >= 1);
    assume_abort_if_not(a > 0 && b > 0);

    // Computing factorial of n and sum simultaneously
    for (int i = 1; i <= n; i++) {
        factorial *= i;
        sum += a + b;

        // Checkpoint for the verification tool to analyze
        __VERIFIER_assert(sum > 0);
    }

    // Verify a specific condition at the end

    return 0;
}