#include <assert.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void reach_error(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int abs(int x) {
    return x < 0 ? -x : x;
}

// Checks if an array is a valid permutation and calculates the signature
int main() {
    int size = __VERIFIER_nondet_int();
    if (size <= 0 || size > 10) {
        return 0; // Restrict the size of the array to prevent overflow
    }

    int *array = (int *)malloc(sizeof(int) * size);
    int *mark = (int *)malloc(sizeof(int) * size);

    if (!array || !mark) {
        free(array);
        free(mark);
        return 0;
    }

    for (int i = 0; i < size; i++) {
        array[i] = __VERIFIER_nondet_int();
        mark[i] = 0;
    }

    int is_permutation = 1;
    for (int i = 0; i < size; i++) {
        if (array[i] < 0 || array[i] >= size) {
            is_permutation = 0;
            break;
        }
        mark[array[i]]++;
    }

    for (int i = 0; i < size && is_permutation; i++) {
        if (mark[i] != 1) {
            is_permutation = 0;
        }
    }

    free(mark);

    if (is_permutation) {
        // Compute the signature (even or odd) of the permutation
        int signature = 1;
        for (int i = 0; i < size; i++) {
            while (array[i] != i) {
                int temp = array[i];
                array[i] = array[temp];
                array[temp] = temp;
                signature = -signature;
            }
        }
        // Expect the signature to be either 1 or -1
        __VERIFIER_assert(abs(signature) == 1);
    }

    free(array);
    return 0;
}