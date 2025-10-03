/*
   Sum of first n natural numbers
   computes sum = 1 + 2 + ... + n
   uses the formula: sum = n * (n + 1) / 2
*/

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sum-of-n-ll.c", 6, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
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
    long long sum, computed_sum;
    int i;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10); // Limiting n to a small value for testing

    sum = 0;
    computed_sum = n * (n + 1) / 2;

    i = 1;
    while (1) {
        if (!(i <= n)) {
            break;
        }

        sum += i;
        i++;
    }

    __VERIFIER_assert(sum == computed_sum);
    return 0;
}