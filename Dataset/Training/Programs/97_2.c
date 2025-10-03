#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int N = __VERIFIER_nondet_int();
    if (N <= 0) {
        return 1;
    }
    assume_abort_if_not(N <= 2147483647 / sizeof(int));

    int *a = malloc(sizeof(int) * N);
    if (a == NULL) {
        return 1; // Handle memory allocation failure
    }

    int i, max_val = -1;
    int odd_product = 1;
    int odd_count = 0;

    for (i = 0; i < N; i++) {
        a[i] = __VERIFIER_nondet_int();

        if (a[i] > max_val) {
            max_val = a[i];
        }

        if (a[i] % 2 != 0) {
            odd_product *= a[i];
            odd_count++;
        }
    }

    if (odd_count > 0) {
    } else {
        __VERIFIER_assert(max_val >= -1);
    }

    free(a);
    return 0;
}