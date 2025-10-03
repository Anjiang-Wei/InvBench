#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int size = __VERIFIER_nondet_int();
    if (size <= 0 || size > 100) {
        return 0;
    }

    int *array = (int *)malloc(sizeof(int) * size);
    if (array == NULL) {
        return 0;
    }

    int i, sum = 0;

    for (i = 0; i < size; i++) {
        array[i] = __VERIFIER_nondet_int();
        if (array[i] < 0 || array[i] > 100) {
            return 0; // Ensure values are in range
        }
        sum += array[i];
    }

    int threshold = __VERIFIER_nondet_int();
    if (threshold < 0 || threshold > size * 100) {
        return 0;
    }

    int count = 0;
    for (i = 0; i < size; i++) {
        if (array[i] < threshold) {
            count++;
        }
    }

    __VERIFIER_assert(count >= 0 && count <= size);

    free(array);
    return 0;
}