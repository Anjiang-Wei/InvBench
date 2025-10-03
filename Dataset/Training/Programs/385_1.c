#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int();
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

#define MAX_ITEMS 1000000

int main() {
    int n, counter_in = 0, counter_out = 0;
    n = __VERIFIER_nondet_int();

    if (n <= 0 || n > MAX_ITEMS) {
        return 0;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        abort();
    }

    for (int i = 0; i < n; ++i) {
        arr[i] = __VERIFIER_nondet_int();
    }

    // Linear scan through array
    for (int i = 0; i < n; ++i) {
        if (arr[i] >= 0) {
            counter_in += arr[i];
        } else {
            counter_out -= arr[i];
        }
    }

    // Validate assumptions about the generated value
    __VERIFIER_assert(counter_in >= 0 || counter_out >= 0);

    // Clean up
    free(arr);

    return 0;
}