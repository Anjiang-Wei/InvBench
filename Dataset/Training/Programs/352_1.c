#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int __VERIFIER_nondet_int() {
    // Simulate a non-deterministic integer generation
    return rand() % 100 - 50; // Random value between -50 and 49
}

int main() {
    int size = __VERIFIER_nondet_int();
    if (size <= 0) {
        size = 5; // Ensuring a positive array size
    }

    int array[100]; // Assume a maximum size of 100 for safety
    int i, sum_positive = 0;

    for (i = 0; i < size; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    for (i = 0; i < size; i++) {
        if (array[i] > 0) {
            sum_positive += array[i];
        }
    }

    // Expected behavior: sum of positive elements is > 0 if there's any positive element
    __VERIFIER_assert(sum_positive >= 0);

    printf("Sum of positive elements: %d\n", sum_positive);
    return 0;
}