#include <assert.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }
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

// New C program with constraints and a loop
int main() {
    int n = __VERIFIER_nondet_int();
    if (n <= 0) {
        return 1;
    }
    assume_abort_if_not(n <= 1000000); // Assume n is within a verified range

    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        return 1;
    }

    int i;
    for (i = 0; i < n; i++) {
        arr[i] = i;
    }

    // Non-trivial computation: sum squares of array elements
    long long sum_of_squares = 0;
    for (i = 0; i < n; i++) {
        sum_of_squares += (long long)arr[i] * (long long)arr[i];
    }

    // Verify: sum_of_squares should be non-negative
    __VERIFIER_assert(sum_of_squares >= 0);

    free(arr);
    return 0;
}