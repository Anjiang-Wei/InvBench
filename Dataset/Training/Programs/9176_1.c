#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 3, "reach_error"); }

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
    int n, x, sum, i;

    // Assume n is a positive number
    n = rand();
    assume_abort_if_not(n > 0 && n < 1000); // Limiting n for verification tools

    x = 0;   // A counter through the loop
    sum = 0; // Sum of even numbers

    for (i = 0; i < n; i++) {
        if (i % 2 == 0) {
            sum += i;
        }

        x++;
    }

    // Ensure that x equals the number of iterations we counted
    __VERIFIER_assert(x == n);

    // If the hypothesis is that for sum of even numbers until n
    // should be less than n*n, this needs to be verified

    printf("Final Sum: %d\n", sum);
    return 0;
}