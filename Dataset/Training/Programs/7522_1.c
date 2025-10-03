#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "parity_checker.c", 5, "reach_error"); }
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

int is_even(int num);

int N;

int main() {
    N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0 && N < 2147483647 / sizeof(int));

    int i;
    int *array = malloc(sizeof(int) * N);
    assume_abort_if_not(array != NULL); // Ensure calloc did not fail

    for (i = 0; i < N; i++) {
        array[i] = i; // Initialize array[i] with index i
    }

    int even_count = 0;

    for (i = 0; i < N; i++) {
        if (is_even(array[i])) {
            even_count++;
        }
    }

    // Pattern: Allocation should confirm whether all positive integers are really scanned for even count correctness.
    for (i = 0; i < N; i++) {
        __VERIFIER_assert((array[i] % 2 == 0 && is_even(array[i])) || (array[i] % 2 != 0 && !is_even(array[i])));
    }

    // Ensure that the even count reflects half of the numbers between 0 and N-1
    // as every even number is evenly spaced by odd number

    free(array);
    return 0;
}

int is_even(int num) {
    return num % 2 == 0;
}