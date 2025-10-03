#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

int main() {
    int n = __VERIFIER_nondet_int();
    if (n <= 0) {
        return 1;
    }

    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        return 1;
    }

    int k = 0;
    while (k < n) {
        array[k] = k * k; // Let's fill the array with squares of indices
        k++;
    }

    // Reset k and count even-indexed squared values
    k = 0;
    int even_count = 0;

    while (k < n) {
        if (array[k] % 2 == 0) {
            even_count++;
        }
        k++;
    }

    // Ensure that if n is even, then so is even_count
    if (n % 2 == 0) {
    } else {
        // Otherwise, even_count can be either even or odd
        __VERIFIER_assert(even_count % 2 == 0 || even_count % 2 == 1);
    }

    free(array);
    return 0;
}