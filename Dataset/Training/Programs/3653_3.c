#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

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

int main() {
    int SIZE = 1000;
    int n = 0, i = 0, j = 0, x = 0, y = 0;
    int sum_odd = 0, sum_even = 0;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= SIZE);

    while (i < n) {
        int num = __VERIFIER_nondet_int();
        assume_abort_if_not(num >= 0 && num <= 100);

        if (num % 2 == 0) {
            sum_even += num;
            x++;
        } else {
            sum_odd += num;
            y++;
        }

        i++;
    }

    __VERIFIER_assert(sum_odd >= 0);

    printf("Total even numbers: %d, Total odd numbers: %d\n", x, y);
    printf("Sum of even numbers: %d, Sum of odd numbers: %d\n", sum_even, sum_odd);

    return 0;
}