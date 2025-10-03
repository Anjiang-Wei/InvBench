#include <assert.h>
#include <stdlib.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
void reach_error() { assert(0); }

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
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 1000);

    int *arr = (int *)malloc(n * sizeof(int));
    assume_abort_if_not(arr != NULL);

    int i;
    int sum = 0;
    for (i = 0; i < n; ++i) {
        arr[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(arr[i] >= 0 && arr[i] <= 100);
        sum += arr[i];
    }

    int targetSum = sum / n;

    int deviationSum = 0;
    for (i = 0; i < n; ++i) {
        int deviation = arr[i] - targetSum;
        if (deviation < 0) {
            deviation = -deviation;
        }
        deviationSum += deviation;
    }

    __VERIFIER_assert(deviationSum >= 0);

    free(arr);
    return 0;
}