#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }
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

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

#define LIMIT 10000

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0 && N < LIMIT);

    int i, sum = 0;
    int *arr = (int *)malloc(sizeof(int) * N);
    int target = 0;

    for (i = 0; i < N; i++) {
        arr[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(arr[i] < LIMIT); // Limit each element to some reasonable size
        sum += arr[i];
    }

    if (N > 0) {
        target = sum / N; // Calculate target as the average of the array elements
    }

    int count_gt_target = 0;
    for (i = 0; i < N; i++) {
        if (arr[i] > target) {
            count_gt_target++;
        }
    }

    __VERIFIER_assert(count_gt_target <= N);

    free(arr);
    return 0;
}