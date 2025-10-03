#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

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
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0);
    assume_abort_if_not(N <= 100);

    int *array = malloc(sizeof(int) * N);
    assume_abort_if_not(array != NULL);

    int greater_than_zero = 0;
    for (int i = 0; i < N; i++) {
        array[i] = __VERIFIER_nondet_int();
        if (array[i] > 0) {
            greater_than_zero++;
        }
    }

    int target = __VERIFIER_nondet_int();
    assume_abort_if_not(target > 0);
    assume_abort_if_not(target <= N);

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (array[i] == target) {
            count++;
        }
    }

    __VERIFIER_assert(count <= N);

    free(array);
    return 0;
}