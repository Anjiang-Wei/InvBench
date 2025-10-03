#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0 && N < 1000); // Ensuring N is within a reasonable range

    int *arr = (int *)malloc(sizeof(int) * N);
    if (!arr) {
        return 1;
    }

    int i;
    for (i = 0; i < N; i++) {
        arr[i] = __VERIFIER_nondet_int();
    }

    int sum = 0;
    for (i = 0; i < N; i++) {
        sum += arr[i];
    }

    int average = sum / N;
    int count_greater_than_average = 0;

    for (i = 0; i < N; i++) {
        if (arr[i] > average) {
            count_greater_than_average++;
        }
    }

    __VERIFIER_assert(count_greater_than_average <= N); // It should never exceed N

    free(arr);
    return 0;
}