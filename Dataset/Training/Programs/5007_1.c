#include <assert.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *);
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0);
    assume_abort_if_not(N <= 2147483647 / sizeof(int));

    int *a = malloc(sizeof(int) * N);
    int sum = 0;

    for (int i = 0; i < N; i++) {
        a[i] = __VERIFIER_nondet_int();
        if (a[i] < 0) {
            a[i] = -a[i]; // Ensures all elements are non-negative
        }
        sum += a[i];
    }

    int target = sum / 2; // Compute half of the sum

    // Find a subset whose sum is as close as possible to the target
    int closest_sum = 0;
    for (int mask = 0; mask < (1 << N); mask++) {
        int subset_sum = 0;
        for (int j = 0; j < N; j++) {
            if (mask & (1 << j)) {
                subset_sum += a[j];
            }
        }
        if (subset_sum <= target && subset_sum > closest_sum) {
            closest_sum = subset_sum;
        }
    }

    __VERIFIER_assert(closest_sum <= target);

    free(a);
    return 0;
}