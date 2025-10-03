#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 6, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();         // Length of the array
    assume_abort_if_not(n > 0 && n <= 1000); // Constraint condition for n

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        return 0; // Check allocation success
    }

    int sum = 0;
    int i;

    // Fill array with values and calculate the sum
    for (i = 0; i < n; i++) {
        arr[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(arr[i] >= -1000 && arr[i] <= 1000); // Constraint for array values
        sum += arr[i];
    }

    // Condition to verify: sum of elements should not exceed a large positive or negative number
    __VERIFIER_assert(sum <= 1000 * n && sum >= -1000 * n);

    free(arr);
    return 0;
}