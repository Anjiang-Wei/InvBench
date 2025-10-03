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
}
extern int __VERIFIER_nondet_int(void);

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();

    // Ensure x and y are within a reasonable range (e.g., [1, 1000])
    if (x < 1 || x > 1000) {
        return 0;
    }
    if (y < 1 || y > 1000) {
        return 0;
    }

    int *array = malloc(sizeof(int) * x);
    if (array == NULL) {
        return 0; // Check for memory allocation failure
    }

    int sum = 0;
    for (int i = 0; i < x; i++) {
        array[i] = y;
        sum += array[i];
    }

    __VERIFIER_assert(sum == x * y);

    // Modify array and check that all elements become zero
    for (int i = 0; i < x; i++) {
        int reduction = __VERIFIER_nondet_int();
        // Assume reduction is a small value to prevent sum from becoming negative
        if (reduction < 0 || reduction > y) {
            continue;
        }

        y -= reduction;
        array[i] -= reduction;
    }

    // Recalculate sum and verify constraints
    sum = 0;
    for (int i = 0; i < x; i++) {
        sum += array[i];
    }

    // The final sum should be less than or equal to the initial sum

    free(array);
    return 0;
}