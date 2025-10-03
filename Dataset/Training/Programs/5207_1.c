#include <assert.h>
#include <stdbool.h>

void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

#define SIZE 10

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
    return;
}

int main(void) {
    int array[SIZE];
    int i, sum = 0;

    // Initialize the array with non-deterministic values
    for (i = 0; i < SIZE; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    i = 0;
    while (i < SIZE) {
        sum += array[i];
        if (array[i] < 0) {
            // Reset sum if a negative number is encountered
            sum = 0;
        }
        i++;
    }

    // We assert that the sum should be non-negative due to the reset feature on a negative number
    __VERIFIER_assert(sum >= 0);

    return 0;
}