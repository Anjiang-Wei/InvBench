#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new-program.c", 3, "reach_error"); }
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
}
extern unsigned int __VERIFIER_nondet_uint(void);

int main() {
    unsigned int num, iter;
    long long factorial, sum_factorial;
    num = __VERIFIER_nondet_uint();
    assume_abort_if_not(num >= 1 && num <= 10);

    iter = 1;
    factorial = 1;
    sum_factorial = 0;

    while (iter <= num) {
        factorial *= iter;
        sum_factorial += factorial;

        if (factorial <= 0 || sum_factorial <= 0) {
            // Overflow check, will eventually trigger reach_error if overflow occurs
            reach_error();
        }

        iter++;
    }

    // This should hold true without overflow, sum_factorial is sum of all factorials from 1! to num!
    __VERIFIER_assert(sum_factorial >= factorial);

    return 0;
}