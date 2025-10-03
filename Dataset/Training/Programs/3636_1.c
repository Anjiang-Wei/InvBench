#include <assert.h>
#include <stdlib.h>

void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0); // Ensure n is positive

    int *array = malloc(sizeof(int) * n);
    assume_abort_if_not(array != NULL);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        array[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(array[i] >= 0); // Ensure each element is non-negative
        sum += array[i];
    }

    int midpoint_value = sum / n;
    int count_less_than_midpoint = 0;

    for (int i = 0; i < n; i++) {
        if (array[i] < midpoint_value) {
            count_less_than_midpoint++;
        }
    }

    __VERIFIER_assert(count_less_than_midpoint <= n);

    free(array);
    return 0;
}