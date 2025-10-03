#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 4, "reach_error"); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
        abort();
    }
}
extern int __VERIFIER_nondet_int(void);

int main() {
    int M = __VERIFIER_nondet_int();
    int threshold = 100;

    assume_abort_if_not(M > 0 && M < 1000); // Arbitrary constraint on input size

    int *array = malloc(sizeof(int) * M);
    assume_abort_if_not(array != NULL); // Ensure memory was allocated

    // Initial setup
    for (int i = 0; i < M; i++) {
        array[i] = i * 2; // Initialize array with even numbers
    }

    // Process array until sum exceeds the threshold
    int sum = 0;
    int count = 0;
    while (count < M && sum <= threshold) {
        sum += array[count];
        count++;
    }

    free(array);

    // After the loop, verify sum condition
    __VERIFIER_assert(sum >= threshold || count == M);

    return 0;
}