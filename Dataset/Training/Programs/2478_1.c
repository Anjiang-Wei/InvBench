#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "newprog.c", 3, "reach_error"); }
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

int mod_sum_check(int n) {
    int i = 1, sum = 0;

    while (i <= n) {
        if (i % 3 == 0) {
            sum += i;
        } else if (i % 5 == 0) {
            sum -= i;
        } else {
            sum += 2 * i;
        }
        i++;
    }

    return sum;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n < 1000);

    int result = mod_sum_check(n);

    // Check whether the result is positive
    __VERIFIER_assert(result >= 0);

    printf("The computed result is: %d\n", result);
    return 0;
}