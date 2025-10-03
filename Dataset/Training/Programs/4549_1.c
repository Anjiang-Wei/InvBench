// A program to compute the fibonacci series up to the nth term
// and verify that each number is the sum of the two preceding ones.

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 9, "reach_error"); }
extern void abort(void);
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

extern int __VERIFIER_nondet_int(void);

int main(void) {
    int n = __VERIFIER_nondet_int();

    // Constraints for verification purposes
    assume_abort_if_not(n >= 0 && n <= 45); // Limiting to prevent arithmetic overflow for simplicity

    if (n == 0 || n == 1) {
        return 0; // In these cases, the series matches itself
    }

    int first = 0, second = 1, next = 0, i = 2;
    int *fib_series = malloc((n + 1) * sizeof(int));

    if (fib_series == NULL) {
        abort(); // To abort if memory allocation fails
    }

    fib_series[0] = first;
    fib_series[1] = second;

    while (i <= n) {
        next = first + second;
        fib_series[i] = next;

        // Checking and verifying that every number is sum of previous two
        __VERIFIER_assert(fib_series[i] == fib_series[i - 1] + fib_series[i - 2]);

        first = second;
        second = next;
        i++;
    }

    free(fib_series);

    return 0;
}