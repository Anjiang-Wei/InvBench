#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example_program.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

#define SIZE 10

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
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
    int array[SIZE];
    int i, sum = 0;

    // Assume SIZE is positive
    assume_abort_if_not(SIZE > 0);

    // Fill array with non-deterministic values from 1 to 100
    for (i = 0; i < SIZE; i++) {
        array[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(array[i] >= 1 && array[i] <= 100);
    }

    // Calculate sum of the array elements
    for (i = 0; i < SIZE; i++) {
        sum += array[i];
    }

    // Check a simple property
    __VERIFIER_assert(sum > 0);

    printf("Sum of array elements: %d\n", sum);
    return 0;
}