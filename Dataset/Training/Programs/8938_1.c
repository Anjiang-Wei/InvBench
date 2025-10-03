#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "find_max.c", 4, "reach_error"); }

int __VERIFIER_nondet_int();

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

#define SIZE 10

int main() {
    int array[SIZE], i;
    int max_val = -2147483648; // Minimum value for an integer

    for (i = 0; i < SIZE; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    for (i = 0; i < SIZE; i++) {
        if (array[i] > max_val) {
            max_val = array[i];
        }
    }

    // Assuming the array contains at least one non-negative number.
    __VERIFIER_assert(max_val >= array[0]);

    if (max_val < 0) {
        printf("All numbers are negative.\n");
    } else {
        printf("Max value found is: %d\n", max_val);
    }

    return 0;
}