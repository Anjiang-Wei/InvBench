#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_example.c", 5, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
 * Program to calculate Fibonacci sequence and check certain properties.
 */
int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 46); // Ensure 'n' is within a practical range to prevent overflow

    int a = 0, b = 1, next, sum = 0;

    // Calculating Fibonacci sequence and their sum up to 'n'
    for (int i = 0; i < n; ++i) {
        next = a + b;
        a = b;
        b = next;
        sum += next;
    }

    // The sum of Fibonacci numbers should be greater than the largest Fibonacci number for n > 1
    if (n > 1) {
        __VERIFIER_assert(sum > b);
    }

    // Print results for verification
    printf("Fibonacci number for n = %d is %d\n", n, b);
    printf("Sum of Fibonacci numbers up to n = %d is %d\n", n, sum);

    return 0;
}