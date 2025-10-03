#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int condition) {
    if (!condition) {
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

int main() {
    int N = __VERIFIER_nondet_int();
    if (N <= 0) {
        return 1;
    }
    assume_abort_if_not(N <= 1000); // Limit N to avoid very large allocations

    int i, key = __VERIFIER_nondet_int();
    int count = 0;
    int *array = (int *)malloc(sizeof(int) * N);

    // Initialize the array with random values but ensure some are negative
    for (i = 0; i < N; i++) {
        array[i] = __VERIFIER_nondet_int() % 200 - 100; // Range [-100, 99]
    }

    // Count how many numbers in the array are less than the key
    for (i = 0; i < N; i++) {
        if (array[i] < key) {
            count++;
        }
    }

    // Check if the counted value makes sense
    __VERIFIER_assert(count >= 0 && count <= N);

    free(array);
    return 0;
}