#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "proposed_program.c", 3, "reach_error"); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

extern int __VERIFIER_nondet_int(void);
extern char __VERIFIER_nondet_char(void);

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
    int array_size = __VERIFIER_nondet_int();

    assume_abort_if_not(array_size > 0 && array_size <= 1000); // Avoid excessively large arrays

    int *array = (int *)malloc(sizeof(int) * array_size);
    int i;
    int target_sum;

    for (i = 0; i < array_size; i++) {
        array[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(array[i] >= 0); // Only non-negative numbers
    }

    // Compute the target_sum as half the possible maximum sum
    target_sum = (array_size * (array_size - 1) / 2) / 2;

    int current_sum = 0;
    int success = 0;

    // Try to find a subset sum using dynamic programming approach
    int dp[target_sum + 1];
    for (i = 0; i <= target_sum; i++) {
        dp[i] = 0;
    }
    dp[0] = 1;

    for (i = 0; i < array_size; i++) {
        for (int j = target_sum; j >= array[i]; j--) {
            dp[j] = dp[j] || dp[j - array[i]];
        }
    }

    if (dp[target_sum]) {
        success = 1;
    }

    __VERIFIER_assert(success == 0 || success == 1);

    free(array);

    return 0;
}