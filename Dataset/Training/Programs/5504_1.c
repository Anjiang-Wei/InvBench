#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= 10000);

    int *array = malloc(sizeof(int) * n);
    assume_abort_if_not(array != NULL);

    for (int i = 0; i < n; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    int min_index = 0;
    for (int i = 1; i < n; i++) {
        if (array[i] < array[min_index]) {
            min_index = i;
        }
    }

    int sum_before_min = 0;
    for (int i = 0; i < min_index; i++) {
        sum_before_min += array[i];
    }

    int distinct_element_count = 0;
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < i; j++) {
            if (array[i] == array[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            distinct_element_count++;
        }
    }

    __VERIFIER_assert(min_index < n);

    free(array);
    return 0;
}