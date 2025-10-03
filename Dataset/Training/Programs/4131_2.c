#include <assert.h>
#include <stdbool.h>

void reach_error() { assert(0); }

// External functions to simulate non-deterministic values
extern unsigned int __VERIFIER_nondet_uint();
extern _Bool __VERIFIER_nondet_bool();

// Custom assert function to stop execution when a condition fails
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Definition of a constant value
#define INCREMENT_VALUE (1)

int main() {
    // Initialize variables
    unsigned int sum = 0;
    unsigned int counter = 0;
    unsigned int limit = __VERIFIER_nondet_uint();

    // Condition to ensure the while loop has a valid execution
    if (limit == 0) {
        return 0;
    }

    // Loop running with non-deterministic behavior
    while (counter < limit) {
        // Non-deterministic choice to increment sum or not
        if (__VERIFIER_nondet_bool()) {
            sum += INCREMENT_VALUE;
        }

        // Always increment the counter
        counter++;

        // Custom check to verify program constraints
    }

    // At the end, sum could be equivalent to counter if INCREMENT_VALUE was always added
    __VERIFIER_assert(sum <= limit);

    return 0;
}