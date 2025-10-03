#include <limits.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example_new.c", 5, "reach_error"); }
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
extern int __VERIFIER_nondet_int(void);

int main() {
    int array_size = __VERIFIER_nondet_int();
    assume_abort_if_not(array_size > 0 && array_size < 100);

    int *numbers = (int *)malloc(sizeof(int) * array_size);
    assume_abort_if_not(numbers != NULL);

    int i, positive_count = 0;

    /* Initialize array with random integers and count positives */
    for (i = 0; i < array_size; ++i) {
        numbers[i] = __VERIFIER_nondet_int();
        if (numbers[i] > 0) {
            ++positive_count;
        }
    }

    /* Check if the positive count is valid */
    __VERIFIER_assert(positive_count >= 0 && positive_count <= array_size);

    /* Verify that increasing positive numbers doesn't overflow */
    for (i = 0; i < positive_count; ++i) {
        if (numbers[i] > 0) {
            numbers[i]++;
            assume_abort_if_not(numbers[i] > 0); // Ensure no overflow occurred
        }
    }

    free(numbers);
    return 0;
}