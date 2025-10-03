/*
 * A C program demonstrating a simple constraint problem.
 * The program sums up the number of even and odd numbers
 * in an array and checks a condition on these sums.
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "custom.c", 10, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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
    return;
}

#define MAX_SIZE 1000
int main() {
    int n;
    int *arr = malloc(sizeof(int) * MAX_SIZE);
    int even_count = 0, odd_count = 0;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n < MAX_SIZE);

    // Fill the array with nondeterministic integers
    for (int i = 0; i < n; i++) {
        arr[i] = __VERIFIER_nondet_int();
    }

    // Count even and odd numbers
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    // Verify that at least one of them isn't zero
    __VERIFIER_assert(even_count > 0 || odd_count > 0);

    free(arr);
    return 0;
}