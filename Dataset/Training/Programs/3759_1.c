#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_example.c", 3, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main(void) {
    unsigned int array_size = __VERIFIER_nondet_uint();
    assume_abort_if_not(array_size > 0 && array_size <= 100000);

    unsigned int array[array_size];
    unsigned int sum = 0;
    unsigned int i;

    // Fill array with nondeterministic values and calculate sum
    for (i = 0; i < array_size; ++i) {
        array[i] = __VERIFIER_nondet_uint();
        sum += array[i];
    }

    unsigned int average = sum / array_size;
    unsigned int count_above_average = 0;

    // Count how many elements are above the average
    for (i = 0; i < array_size; ++i) {
        if (array[i] > average) {
            count_above_average++;
        }
    }

    // Verify that the count of elements above the average is within the array size
    __VERIFIER_assert(count_above_average <= array_size);

    printf("Number of elements above the average: %u\n", count_above_average);

    return 0;
}