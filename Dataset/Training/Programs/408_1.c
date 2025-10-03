#include <stdio.h>
#include <stdlib.h>

// Function declarations
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_example.c", 3, "reach_error"); }
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

// The main function implementing a loop with constraints
int main() {
    int n, sum, i;

    // Obtain a non-deterministic integer
    n = __VERIFIER_nondet_int();

    // Assume n is between 1 and 100
    assume_abort_if_not(n > 0 && n <= 100);

    sum = 0;
    i = 1;

    // Loop to calculate the sum of the first n natural numbers
    while (i <= n) {
        sum = sum + i;
        __VERIFIER_assert(sum == (i * (i + 1)) / 2);
        i = i + 1;
    }

    // Final assertion to check if the sum is correct

    return 0;
}