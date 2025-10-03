#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { printf("Error reached\n"); }

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

int main() {
    int sum = 0;
    int step = 1;
    int limit = __VERIFIER_nondet_int();
    int target = 100;

    // Assume that the randomly chosen limit is between 20 and 50.
    if (limit < 20 || limit > 50) {
        return 0;
    }

    // Loop to accumulate values incremented by 'step'
    // The condition ensures no overflow in this simplistic scenario
    while (sum + step <= limit) {
        sum += step;
        step += 1;
    }

    // We expect sum to never exceed the limit
    __VERIFIER_assert(sum <= limit);

    // Additional check to ensure that the sum eventually reaches the target
    if (sum == target) {
        printf("Target reached: %d\n", sum);
    } else {
        // We can reach here if limit is too low to reach the target
        printf("Target not reached, current sum: %d\n", sum);
    }

    return 0;
}