#include <stdio.h>
#include <stdlib.h>

// External functions for verification
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 7, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main(void) {
    int a, b, n;
    long long sum = 0;
    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 2 && a <= 10);

    b = __VERIFIER_nondet_int();
    assume_abort_if_not(b >= 1 && b <= 5);

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 10);

    int i = 0;
    while (i < n) {
        sum += a * b;
        if (sum > 1000) {
            break;
        }
        i++;
    }

    __VERIFIER_assert(sum < 2000);

    printf("Value of sum: %lld\n", sum);

    return 0;
}