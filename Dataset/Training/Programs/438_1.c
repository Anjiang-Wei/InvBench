#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 10, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
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

int main() {
    int array_size = __VERIFIER_nondet_int();
    assume_abort_if_not(array_size > 0 && array_size <= 1000);

    int *array = (int *)malloc(sizeof(int) * array_size);
    assume_abort_if_not(array != NULL);

    int i, j;
    for (i = 0; i < array_size; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    int threshold = __VERIFIER_nondet_int();
    int count = 0;

    for (i = 0; i < array_size; i++) {
        // Increment count if element is greater than threshold
        if (array[i] > threshold) {
            count++;
        }
    }

    __VERIFIER_assert(count >= 0 && count <= array_size);

    for (i = 0; i < count; i++) {
        // Ensure the first 'count' elements were valid counts
    }

    free(array);
    return 0;
}