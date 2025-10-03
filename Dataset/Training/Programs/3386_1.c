#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom-program.c", 5, "reach_error"); }
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
extern int __VERIFIER_nondet_int(void);

int main() {
    int n, m;
    long long factorial = 1, sum = 0, i = 1;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10);

    m = __VERIFIER_nondet_int();
    assume_abort_if_not(m >= 1 && m <= 10);

    // Perform an iterative computation
    while (i <= n) {
        factorial *= i;
        if (factorial % m == 0) {
            sum += i;
        }
        i++;
    }

    printf("Sum of indices with factorial multiples of %d: %lld\n", m, sum);

    // Check a meaningful invariant (sum should never be greater than 55 in this restricted range)
    __VERIFIER_assert(sum <= 55);

    return 0;
}