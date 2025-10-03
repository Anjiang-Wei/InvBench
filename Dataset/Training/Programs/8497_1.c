#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_prog.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int n, i, sum_even, sum_odd;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 10);

    sum_even = 0;
    sum_odd = 0;
    i = 1; // start from 1 to check if we encounter even or odd

    while (i <= n) {
        if (i % 2 == 0) {
            sum_even += i;
        } else {
            sum_odd += i;
        }
        i++;
    }

    // Suppose the sum of odd numbers minus the sum of even numbers should be less than or equal to the total count of numbers
    __VERIFIER_assert(sum_odd - sum_even <= n);

    // Just for checking results
    printf("Sum of odd numbers: %d\n", sum_odd);
    printf("Sum of even numbers: %d\n", sum_even);

    return 0;
}