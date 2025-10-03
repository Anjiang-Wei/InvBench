#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example_program.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int compute_factorial(int n) {
    if (n < 0) {
        return -1; // Invalid input case
    }
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int compute_sum_of_squares(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * i;
    }
    return sum;
}

int main() {
    int n = 5;
    int factorial = compute_factorial(n);
    int sum_sq = compute_sum_of_squares(n);

    // Validation part, should be correct for given n=5
    __VERIFIER_assert(factorial == 120);

    // Loop with constraints
    int x = 0;
    int y = 0;
    while (x < factorial) {
        x += 2;
        y++;
    }

    // Ensure that the loop correctly processes
    return 0;
}