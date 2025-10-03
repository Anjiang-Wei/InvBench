#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "new-program.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int sum = 0;
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 20);

    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    int expected_sum = n * (n + 1) / 2;
    __VERIFIER_assert(sum == expected_sum);

    printf("Sum of first %d natural numbers is: %d\n", n, sum);

    return 0;
}