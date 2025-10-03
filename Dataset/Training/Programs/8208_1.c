#include <assert.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }
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
    return;
}
extern int __VERIFIER_nondet_int(void);

void *custom_malloc(unsigned int size) {
    void *ptr = malloc(size);
    assume_abort_if_not(ptr != NULL);
    return ptr;
}

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0 && N <= 1000);

    int *arr = (int *)custom_malloc(N * sizeof(int));
    int *reverseArr = (int *)custom_malloc(N * sizeof(int));

    // Initialize array with some values
    for (int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }

    // Reverse the array
    for (int i = 0; i < N; i++) {
        reverseArr[N - i - 1] = arr[i];
    }

    // Check if the reversed array's first element is equal to the original array's last element
    __VERIFIER_assert(reverseArr[0] == arr[N - 1]);

    // Free allocated memory
    free(arr);
    free(reverseArr);

    return 0;
}