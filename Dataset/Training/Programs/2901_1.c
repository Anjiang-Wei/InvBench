#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "custom_program.c", 3, "reach_error");
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

_Bool __VERIFIER_nondet_bool();

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int n = 5; // set the value of n for which factorial is to be calculated
    int fact = 1;
    int i;

    for (i = 1; i <= n; i++) {
        fact *= i;
    }

    // Use a loop to verify that the computed factorial is correct
    int computed_fact = factorial(n);
    __VERIFIER_assert(computed_fact == fact);

    // Additional logic
    int arr[5];
    int len = 0;
    _Bool c = __VERIFIER_nondet_bool();

    while (c) {
        if (len == 4) {
            len = 0;
        }
        arr[len] = len * 2;
        len++;
    }

    // Ensure the loop modifies the array within bounds
    for (i = 0; i < 5; i++) {
    }

    return 0;
}