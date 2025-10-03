#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void *safe_malloc(size_t size) {
    void *ptr = malloc(size);
    assume_abort_if_not(ptr != NULL);
    return ptr;
}

int main() {
    int M = __VERIFIER_nondet_int();
    assume_abort_if_not(M > 0 && M <= 1000);

    int *array = (int *)safe_malloc(sizeof(int) * M);

    int sum = 0;
    for (int i = 0; i < M; i++) {
        array[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(array[i] >= 0 && array[i] <= 100);
        sum += array[i];
    }

    int total_expected_sum = M * 100;
    __VERIFIER_assert(sum <= total_expected_sum);

    free(array);
    return 0;
}