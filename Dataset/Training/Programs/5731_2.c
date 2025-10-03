#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 8, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

int sum_square_diff(int n) {
    int sum_of_squares = 0;
    int square_of_sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum_of_squares += i * i;
        square_of_sum += i;
    }
    square_of_sum *= square_of_sum;
    return square_of_sum - sum_of_squares;
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    int N = __VERIFIER_nondet_int();
    if (N <= 0) {
        return 1; // Avoids non-positive values
    }

    int result = sum_square_diff(N);

    // We know that if N is 1, result must be 0, because (1^2 = 1 and 1^2 = 1)
    if (N == 1) {
    }

    // If N is 2, (1^2 + 2^2 = 1 + 4 = 5) and (1 + 2)^2 = 9, so result is 4
    if (N == 2) {
        __VERIFIER_assert(result == 4);
    }

    printf("Sum of squares difference for N=%d is %d\n", N, result);

    return 0;
}