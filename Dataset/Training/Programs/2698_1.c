#include <assert.h>
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

void *custom_malloc(size_t size) {
    void *ptr = malloc(size);
    if (!ptr) {
        abort();
    }
    return ptr;
}

int main() {
    int N = __VERIFIER_nondet_int();
    if (N <= 0) {
        return 0;
    }

    int *array = (int *)custom_malloc(N * sizeof(int));
    int sum = 0;

    for (int i = 0; i < N; i++) {
        array[i] = __VERIFIER_nondet_int() % 10; // Assign random values between 0 and 9
    }

    for (int i = 0; i < N; i++) {
        sum += array[i];
    }

    float average = (float)sum / N;

    for (int i = 0; i < N; i++) {
        if (array[i] > average) {
            __VERIFIER_assert(array[i] > average);
        }
    }

    free(array);
    return 0;
}