#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int calculate_sum(int limit) {
    int sum = 0;
    for (int i = 1; i <= limit; i++) {
        sum += i;
    }
    return sum;
}

void verify_sum(int computed_sum, int expected_sum) {
    __VERIFIER_assert(computed_sum == expected_sum);
}

int main() {
    int limit = 100;
    int expected_sum = (limit * (limit + 1)) / 2;
    int computed_sum = calculate_sum(limit);

    verify_sum(computed_sum, expected_sum);

    printf("Sum of numbers from 1 to %d is %d\n", limit, computed_sum);
    return 0;
}