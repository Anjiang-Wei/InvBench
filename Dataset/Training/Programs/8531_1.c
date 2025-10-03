#include <limits.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_prog.c", 5, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    int array_length = __VERIFIER_nondet_int();
    assume_abort_if_not(array_length > 0 && array_length <= 2147483647 / sizeof(int));

    int *arr = malloc(sizeof(int) * array_length);
    if (arr == NULL) {
        return 1;
    }

    // Initialize the array elements with ascending even numbers starting from 0.
    for (int i = 0; i < array_length; ++i) {
        arr[i] = i * 2;
    }

    // Another computation: Cumulative product
    unsigned long long product = 1;
    for (int i = 0; i < array_length; ++i) {
        product = product * arr[i];

        // Verify that the product does not overflow in unsigned 64-bit integer arithmetic.
        if (product < arr[i]) {
            free(arr);
            abort();
        }
    }

    free(arr);

    // Another constraint
    __VERIFIER_assert(product % 2 == 0 || product == 1);

    return 0;
}