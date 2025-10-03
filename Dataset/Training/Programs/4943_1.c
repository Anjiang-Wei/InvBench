#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "new_program.c", 3, "reach_error");
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

#define MAX_CAPACITY 1000

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= MAX_CAPACITY);

    int *array = (int *)malloc(n * sizeof(int));
    assume_abort_if_not(array != NULL);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        // Initialize array with nondeterministic values
        array[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(array[i] >= 0); // Array elements must be non-negative
        sum += array[i];
    }

    int target_sum = __VERIFIER_nondet_int();
    assume_abort_if_not(target_sum >= 0 && target_sum <= n * (n - 1) / 2);

    int computed_sum = 0;
    for (int i = 0; i < n; i++) {
        computed_sum += array[i];
        if (computed_sum > target_sum) {
            computed_sum -= array[i];
            break;
        }
    }

    // Check that the computed sum is not greater than the target sum
    __VERIFIER_assert(computed_sum <= target_sum);

    free(array);
    return 0;
}