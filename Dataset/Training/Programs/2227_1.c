#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() {
    printf("Error reached\n");
    abort();
}
extern int __VERIFIER_nondet_int(void);
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

int main() {
    int n = __VERIFIER_nondet_int();
    if (n <= 0) {
        return 1;
    }

    int *array = malloc(sizeof(int) * n);
    if (array == NULL) {
        return 1;
    }

    int i;
    for (i = 0; i < n; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    int pos_count = 0;
    int neg_count = 0;
    int zero_count = 0;

    for (i = 0; i < n; i++) {
        if (array[i] > 0) {
            pos_count++;
        } else if (array[i] < 0) {
            neg_count++;
        } else {
            zero_count++;
        }
    }

    // Verifying that the sum of positive, negative and zero counts equals n
    __VERIFIER_assert(pos_count + neg_count + zero_count == n);

    free(array);
    return 0;
}