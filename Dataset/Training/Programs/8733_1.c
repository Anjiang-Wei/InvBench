// Your complete C program here
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "my_example.c", 6, "reach_error"); }
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

#define ARR_SIZE 10

int main() {
    int arr[ARR_SIZE];
    int i, square_limit;

    // Initialize the array with non-deterministic values
    square_limit = __VERIFIER_nondet_int();

    assume_abort_if_not(square_limit > 0);

    for (i = 0; i < ARR_SIZE; i++) {
        arr[i] = __VERIFIER_nondet_int();
    }

    // Squaring values that are below the square_limit
    for (i = 0; i < ARR_SIZE; i++) {
        if (arr[i] > 0 && arr[i] < square_limit) {
            int square = arr[i] * arr[i];
            // Assert that the square is still below square_limit
            __VERIFIER_assert(square > 0 && square < square_limit * square_limit);
        }
    }

    return 0;
}