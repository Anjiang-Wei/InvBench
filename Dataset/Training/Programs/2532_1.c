#include <assert.h>
#include <stdlib.h>

#define SIZE 100

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void reach_error() { assert(0); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

int find_maximum(int *arr, int n) {
    if (n <= 0) {
        return 0;
    }
    int max_value = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
    }
    return max_value;
}

int find_minimum(int *arr, int n) {
    if (n <= 0) {
        return 0;
    }
    int min_value = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min_value) {
            min_value = arr[i];
        }
    }
    return min_value;
}

int array_sum(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0 && N <= SIZE);

    int *array = (int *)malloc(N * sizeof(int));
    assume_abort_if_not(array != NULL);

    for (int i = 0; i < N; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    int max = find_maximum(array, N);
    int min = find_minimum(array, N);
    int sum = array_sum(array, N);

    // Constraints based on known array properties
    __VERIFIER_assert(max >= min);

    free(array);
    return 0;
}