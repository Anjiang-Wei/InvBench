#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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

int main() {
    int n;
    int sum_even = 0, sum_odd = 0, total_sum = 0;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= 1000000); // Ensure reasonable range

    int *arr = (int *)malloc(n * sizeof(int));

    // Initialize array with some values
    for (int i = 0; i < n; i++) {
        arr[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(arr[i] >= 0 && arr[i] <= 100); // Ensure reasonable values
    }

    // Compute sums of even and odd indexed elements
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            sum_even += arr[i];
        } else {
            sum_odd += arr[i];
        }
        total_sum += arr[i];
    }

    // Check key property of sum
    __VERIFIER_assert(total_sum == sum_even + sum_odd);

    free(arr);
    return 0;
}