#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "proposed_program.c", 3, "reach_error"); }
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
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n < 1000);

    int *arr = (int *)malloc(sizeof(int) * n);
    if (arr == NULL) {
        return 1;
    }

    int check_sum = 0;

    for (int i = 0; i < n; i++) {
        int value = __VERIFIER_nondet_int();
        assume_abort_if_not(value >= 0 && value <= 100);
        arr[i] = value;
        check_sum += value;
    }

    int odd_count = 0;
    int sum_of_squares = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            odd_count++;
        }
        sum_of_squares += arr[i] * arr[i];
    }

    free(arr);

    // Verifying some simple properties
    __VERIFIER_assert(sum_of_squares >= 0); // Since all numbers are non-negative

    printf("Number of odd elements: %d\n", odd_count);
    printf("Sum of squares: %d\n", sum_of_squares);

    return 0;
}