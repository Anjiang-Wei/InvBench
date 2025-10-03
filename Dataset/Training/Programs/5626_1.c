#include <assert.h>
#include <stdbool.h>

// Definition for the reach error function
void reach_error(void) { assert(0); }

// Simulation of non-deterministic integer and boolean
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

// Assert function to verify the condition
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a, b, limit;
    long sum_a = 0, sum_b = 0;

    // Initialize non-deterministically
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    limit = __VERIFIER_nondet_int();

    // Constraints on non-deterministic inputs
    if (limit <= 0 || a < 0 || b < 0) {
        return 0;
    }

    int i = 0;
    int j = 0;

    while (i < limit && j < limit) {
        sum_a += a;
        sum_b += b;

        i++;
        if (i % 3 == 0) { // introduce some different behavior
            j += 2;
        } else {
            j++;
        }
    }

    // Assert to verify properties of sum_a and sum_b
    __VERIFIER_assert(sum_a >= 0 && sum_b >= 0);

    return 0;
}