#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 8, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
        abort();
    }
}

int sum_of_squares(int *array, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i] * array[i];
    }
    return sum;
}

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0 && N < 100); // Assume N is positive and reasonable

    int *arr = (int *)malloc(N * sizeof(int));
    assume_abort_if_not(arr != NULL); // Check allocation success

    for (int i = 0; i < N; i++) {
        arr[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(arr[i] >= -50 && arr[i] <= 50); // Assume values within a range
    }

    int sum_squares = sum_of_squares(arr, N);

    // Constraint verification: The sum of squares should be non-negative
    __VERIFIER_assert(sum_squares >= 0);

    free(arr);
    return 0;
}