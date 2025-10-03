#include <assert.h>
#include <stdio.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

int main() {
    int max_iterations, current_sum = 0, i = 0;
    int limit = __VERIFIER_nondet_int();

    assume_abort_if_not(limit > 1);

    max_iterations = 100; // Setting an arbitrary limit for iterations

    while (i < max_iterations) {
        if (current_sum >= limit) {
            break;
        }
        current_sum += i;
        i++;
    }

    // Check that the loop termination condition holds: either i reached max_iterations or current_sum >= limit

    // Ensure the sum does not exceed the limits when the loop finishes
    __VERIFIER_assert(current_sum - i < limit);

    printf("Final sum is: %d\n", current_sum);

    return 0;
}