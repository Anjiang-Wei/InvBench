#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_example.c", 8, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0);
    assume_abort_if_not(N <= 10000);

    int *arr = (int *)malloc(sizeof(int) * N);
    assume_abort_if_not(arr != 0);

    int i, threshold = 50;
    int count_above_threshold = 0, sum = 0;

    for (i = 0; i < N; i++) {
        arr[i] = __VERIFIER_nondet_int();
        if (arr[i] % 2 == 0) {
            arr[i] = arr[i] / 2;
        } else {
            arr[i] = arr[i] * 3 + 1;
        }
    }

    for (i = 0; i < N; i++) {
        if (arr[i] > threshold) {
            count_above_threshold++;
        }
        sum += arr[i];
    }

    // Check that count_above_threshold shouldn't exceed N
    __VERIFIER_assert(count_above_threshold <= N);

    // Perform another meaningful assertion
    return 0;
}