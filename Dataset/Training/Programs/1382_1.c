// Program to compute the sum of even numbers up to a nondeterministic limit

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sum_even.c", 5, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
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

int main() {
    int limit, sum, i;
    limit = __VERIFIER_nondet_int();

    // Assume a reasonable upper limit for demonstration purposes
    assume_abort_if_not(limit >= 0 && limit <= 1000);

    sum = 0;
    i = 0;

    // Calculate the sum of even numbers from 0 to `limit`
    while (i <= limit) {
        if (i % 2 == 0) {
            sum += i;
        }
        i++;
    }

    // Assert that the sum is only incremented by even numbers
    __VERIFIER_assert(sum >= 0);

    printf("Sum of even numbers up to %d is %d\n", limit, sum);

    return 0;
}