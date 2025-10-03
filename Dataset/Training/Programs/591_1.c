#include <assert.h>
#include <stdbool.h>

void reach_error(void) { assert(0); }
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* Introduce a program that calculates the sum of even numbers up to a given limit */

int main() {
    int limit = __VERIFIER_nondet_int();
    if (limit < 0) {
        return 0;
    }

    int sum_even = 0;
    int count = 0;

    // Loop to find the sum of even numbers less than or equal to `limit`
    while (count <= limit) {
        if (count % 2 == 0) {
            sum_even += count;
        }
        count++;
    }

    // Asserting properties
    __VERIFIER_assert(sum_even >= 0);      // Sum should always be non-negative
    __VERIFIER_assert(sum_even % 2 == 0);  // Sum of even numbers is even
    __VERIFIER_assert(count == limit + 1); // Loop should run `limit + 1` times

    return 0;
}