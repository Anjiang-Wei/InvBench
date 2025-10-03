#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 5, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int MAX_SIZE = 1000000;

int sum_of_squares(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i] * arr[i];
    }
    return sum;
}

int main() {
    int array_size = __VERIFIER_nondet_int();
    if (array_size <= 0 || array_size > MAX_SIZE) {
        return 0;
    }

    int *array = (int *)malloc(sizeof(int) * array_size);
    if (array == NULL) {
        return 0;
    }

    for (int i = 0; i < array_size; ++i) {
        array[i] = __VERIFIER_nondet_int();
    }

    int sum_sq = sum_of_squares(array, array_size);

    // Check that the sum of squares is non-negative
    // This should logically hold, as a square of any integer is non-negative
    __VERIFIER_assert(sum_sq >= 0);

    free(array);
    return 0;
}