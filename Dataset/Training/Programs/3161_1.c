#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 4, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= 10);

    int count_positive = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        int number = __VERIFIER_nondet_int();
        assume_abort_if_not(number >= -100 && number <= 100);

        if (number > 0) {
            count_positive++;
        }

        sum += number;
    }

    __VERIFIER_assert(count_positive <= n);

    return 0;
}