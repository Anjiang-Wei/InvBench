#include <assert.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }
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
extern unsigned int __VERIFIER_nondet_uint(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

#define SIZE 5

int main() {
    int arr[SIZE];
    unsigned int i;

    // Initialize the array with nondeterministic values
    for (i = 0; i < SIZE; i++) {
        arr[i] = __VERIFIER_nondet_int();
    }

    int sum = 0;
    int limit = __VERIFIER_nondet_int();
    assume_abort_if_not(limit >= 0);

    for (i = 0; i < SIZE; i++) {
        if (arr[i] >= limit) {
            sum += arr[i];
        }
    }

    // Assert that the sum is not negative (given constraints)
    __VERIFIER_assert(sum >= 0);

    return 0;
}