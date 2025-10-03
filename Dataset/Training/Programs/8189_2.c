#include <assert.h>
#include <stdio.h>
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
    int total_sum = 0;
    int max_iterations = 50;
    int limit = 1000;
    int iteration_count = 0;

    while (iteration_count < max_iterations) {
        int increment = __VERIFIER_nondet_int();
        if (increment < 0) {
            continue; // Ignore negative increments
        }

        total_sum += increment;

        if (total_sum > limit) {
            total_sum -= limit; // Wrap around if limit is exceeded
        }

        iteration_count++;
    }

    // Post-conditions
    __VERIFIER_assert(iteration_count == max_iterations);

    printf("Final total_sum: %d\n", total_sum);
    printf("Iterations conducted: %d\n", iteration_count);

    return 0;
}