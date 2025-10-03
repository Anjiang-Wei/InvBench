#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }
extern void abort(void);
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

#define MAX_SIZE 1000

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= MAX_SIZE);

    int *arr = (int *)malloc(n * sizeof(int));
    assume_abort_if_not(arr != NULL);

    int sum = 0;
    int i;

    for (i = 0; i < n; i++) {
        arr[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(arr[i] >= 0); // Assume all elements are non-negative
        sum += arr[i];
    }

    int avg = sum / n;
    int j = 0;
    int countAboveAvg = 0;

    while (j < n) {
        if (arr[j] > avg) {
            countAboveAvg++;
        }
        j++;
    }

    // Verification condition: count of elements above average should be no more than n
    __VERIFIER_assert(countAboveAvg <= n);

    free(arr);
    return 0;
}