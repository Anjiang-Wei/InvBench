#include <stdio.h>
#include <stdlib.h>

void reach_error() {
    printf("Reach error\n");
    abort();
}

extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR:
        reach_error();
    }
}

int main() {
    int total_points = 0, current_points = 0, level_limit;
    int accumulation_factor;
    int counter = 0;

    accumulation_factor = __VERIFIER_nondet_int(); // unknown accumulation factor
    level_limit = __VERIFIER_nondet_int();         // unknown level limit

    // Assumptions about valid range for accumulation_factor and level_limit
    assume_abort_if_not(accumulation_factor >= 1 && accumulation_factor <= 5);
    assume_abort_if_not(level_limit >= 1 && level_limit <= 10);

    current_points = 0;

    while (counter++ < 100) {
        // Condition to stop looping
        if (current_points >= level_limit) {
            break;
        }

        // Accumulate points based on some factor multiplier
        current_points += accumulation_factor;

        // Ensure an invariant relationship holds through the process
    }

    // Final evaluation
    total_points = current_points;
    __VERIFIER_assert(total_points >= 0);

    return 0;
}