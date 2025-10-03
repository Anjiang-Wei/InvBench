#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "generated.c", 3, "reach_error"); }

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
extern _Bool __VERIFIER_nondet_bool();

#define MAX_ARRAY_SIZE 1000

int main() {
    int size = __VERIFIER_nondet_int();
    assume_abort_if_not(size > 0 && size < MAX_ARRAY_SIZE);

    int *arr = (int *)malloc(sizeof(int) * size);
    assume_abort_if_not(arr != NULL);

    int total = 0;
    for (int i = 0; i < size; i++) {
        arr[i] = __VERIFIER_nondet_int();                   // Populate with nondeterministic integers
        assume_abort_if_not(arr[i] >= 0 && arr[i] <= 1000); // Assume bounded array values for realism
        total += arr[i];
    }

    int threshold = __VERIFIER_nondet_int();
    assume_abort_if_not(threshold > 0);

    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > threshold) {
            counter++;
        }
    }

    // Simple assertion: the counter should not exceed the array size

    // Let's introduce a secondary condition: total sum must be within a reasonable bound
    __VERIFIER_assert(total <= size * 1000);

    free(arr);
    return 0;
}