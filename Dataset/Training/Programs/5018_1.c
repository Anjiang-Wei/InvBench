#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 7, "reach_error"); }
extern void abort(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int N = __VERIFIER_nondet_int();

    if (N <= 0) {
        return 0;
    }
    assume_abort_if_not(N <= 1000);

    int *arr = (int *)malloc(sizeof(int) * N);
    if (arr == NULL) {
        return 0;
    }

    int i, sum = 0;

    for (i = 0; i < N; i++) {
        arr[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(arr[i] >= 0);
        sum += arr[i];
    }

    int average = sum / N;
    int count_above_avg = 0;

    for (i = 0; i < N; i++) {
        if (arr[i] > average) {
            count_above_avg++;
        }
    }

    __VERIFIER_assert(count_above_avg >= 0);

    free(arr);
    return 0;
}