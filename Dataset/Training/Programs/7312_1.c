#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "dynamic-range.c", 5, "reach_error"); }
extern void abort(void);
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

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0 && N < 10000);
    int *array = (int *)malloc(sizeof(int) * N);

    int min = __VERIFIER_nondet_int();
    int max = __VERIFIER_nondet_int();
    assume_abort_if_not(min < max);

    for (int i = 0; i < N; i++) {
        array[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(array[i] >= min && array[i] <= max);
    }

    // Simulate some meaningful logic: calculate dynamic range
    int observed_min = array[0];
    int observed_max = array[0];
    for (int i = 1; i < N; i++) {
        if (array[i] < observed_min) {
            observed_min = array[i];
        }
        if (array[i] > observed_max) {
            observed_max = array[i];
        }
        assume_abort_if_not(array[i] >= min && array[i] <= max);
    }

    int dynamic_range = observed_max - observed_min;
    printf("Dynamic range of observed data: %d\n", dynamic_range);

    // Verification: ensure dynamic range is never negative
    __VERIFIER_assert(dynamic_range >= 0);

    free(array);
    return 0;
}