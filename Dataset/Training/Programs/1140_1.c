#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 4, "reach_error"); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}
int __VERIFIER_nondet_int();

#define MAX_SIZE 1000000
#define THRESHOLD 500000

int main() {
    unsigned int a = 0, b = 0;
    unsigned int sum = 0;

    // Non-deterministically choosing the array size
    int size = __VERIFIER_nondet_int();
    assume_abort_if_not(size > 0 && size <= MAX_SIZE);

    unsigned int array[MAX_SIZE];

    // Filling the array with non-deterministic values and computing their sum
    for (int i = 0; i < size; i++) {
        array[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(array[i] < THRESHOLD);
        sum += array[i];
    }

    // Compute the number of elements below and above half the threshold
    unsigned int half_threshold = THRESHOLD / 2;
    for (int i = 0; i < size; i++) {
        if (array[i] < half_threshold) {
            a++;
        } else {
            b++;
        }
    }

    // Assert that the total number of elements is equal to the size
    __VERIFIER_assert(a + b == size);

    // Print the results
    printf("Sum of array elements: %u\n", sum);
    printf("Number of elements below half the threshold: %u\n", a);
    printf("Number of elements above or equal to half the threshold: %u\n", b);

    return 0;
}