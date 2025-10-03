#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 7, "reach_error"); }
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
extern int __VERIFIER_nondet_int();

int main() {
    int M = __VERIFIER_nondet_int();
    int t = __VERIFIER_nondet_int();
    assume_abort_if_not(M > 0);
    assume_abort_if_not(M <= 1000);
    assume_abort_if_not(t > 0);
    assume_abort_if_not(t <= 1000);

    long long result = 0;
    int divisor = 3;

    for (int i = 1; i <= M; ++i) {
        if (i % divisor == 0) {
            result += i * t;
        } else {
            result += i;
        }
    }

    // Final assertion to verify expected behavior
    __VERIFIER_assert(result > 0);

    printf("Result: %lld\n", result);
    return 0;
}