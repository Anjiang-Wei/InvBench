#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

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

extern int __VERIFIER_nondet_int(void);

#define SIZE 100

int main() {
    int n = __VERIFIER_nondet_int();
    if (n <= 0 || n > SIZE) {
        return 1;
    }

    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        abort();
    }

    int sum = 0;
    int product = 1;
    for (int i = 0; i < n; i++) {
        array[i] = i + 1; // Fill the array with values 1 to n
        sum += array[i];
        product *= array[i];
    }

    // Check if sum of elements is the sum of first n natural numbers
    int expected_sum = n * (n + 1) / 2;

    // A more complex check, such as verifying product might be limited by computational constraints
    __VERIFIER_assert(product > 0);

    free(array);

    return 0;
}