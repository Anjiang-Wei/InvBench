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
    int n, i;
    long long sum_squares, square_sum;

    // Get a non-deterministic value for `n` which should be between 1 and 5
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 5);

    sum_squares = 0;
    square_sum = 0;

    i = 1;

    while (i <= n) {
        sum_squares += i * i; // Sum of squares
        square_sum += i;      // Sum of numbers
        i++;
    }

    square_sum = square_sum * square_sum; // Square of sum

    // Assert the inequality would hold because (sum of squares) <= (square of sum)
    __VERIFIER_assert(sum_squares <= square_sum);

    // Print the result for user
    printf("For n = %d: Sum of squares = %lld, Square of sum = %lld\n", n, sum_squares, square_sum);

    return 0;
}