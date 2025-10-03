/*
 * Pattern Example Program
 * This program simulates a resource allocation routine using a loop and verification checks.
 * The loop allocates resources in a way that ensures an invariant relationship between allocation and available resources.
 */

#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int allocated = 0;
    int limit = __VERIFIER_nondet_int();
    int step = __VERIFIER_nondet_int();
    int resources = __VERIFIER_nondet_int();

    assume_abort_if_not(limit > 0);
    assume_abort_if_not(step > 0);
    assume_abort_if_not(resources >= limit);

    while (allocated < resources) {
        allocated += step;
        if (allocated > limit) {
            allocated -= step; // cannot allocate beyond the limit
            break;
        }
    }

    // Verify that we've either allocated up to the limit or stopped early

    // Ensure that the remaining resources are non-negative
    int remaining = resources - allocated;
    __VERIFIER_assert(remaining >= 0);

    return 0;
}