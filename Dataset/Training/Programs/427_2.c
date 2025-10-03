#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 4, "reach_error"); }
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int arraySize = __VERIFIER_nondet_int();
    assume_abort_if_not(arraySize > 0 && arraySize <= 50);

    int array[arraySize];
    int sum = 0;
    int i;

    for (i = 0; i < arraySize; i++) {
        array[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(array[i] >= 0 && array[i] <= 100);
        sum += array[i];
    }

    int average = sum / arraySize;

    for (i = 0; i < arraySize; i++) {
    }

    __VERIFIER_assert(sum >= 0);

    printf("Sum: %d\n", sum);
    printf("Average: %d\n", average);

    return 0;
}