/* Program to simulate weighted value computation based on conditions */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "weighted_value_calculation.c", 3, "reach_error");
}

extern int __VERIFIER_nondet_int(void);
extern void abort(void);

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

int main() {
    int weight1, weight2, total_value;
    long long cumulative_weight, temp_value;
    int max_threshold = 50; // arbitrary maximum for simulation
    int count = 0;

    weight1 = __VERIFIER_nondet_int();
    assume_abort_if_not(weight1 >= 1 && weight1 <= 10);
    weight2 = __VERIFIER_nondet_int();
    assume_abort_if_not(weight2 >= 1 && weight2 <= 10);

    assume_abort_if_not(weight1 != weight2); // Ensure weights are not equal to add complexity

    cumulative_weight = weight1 + weight2;
    temp_value = (weight1 * weight2) % max_threshold;

    while (count++ < 20) {
        if (cumulative_weight >= max_threshold) {
            break;
        }

        if (temp_value < max_threshold / 2) {
            cumulative_weight += weight1;
        } else {
            cumulative_weight += weight2;
        }

        temp_value = (temp_value * 2 + cumulative_weight) % max_threshold;
    }

    // Validate the final cumulative weight meets the expectations
    __VERIFIER_assert(cumulative_weight >= weight1 + weight2);

    printf("Computed cumulative weight: %lld\n", cumulative_weight);
    return 0;
}