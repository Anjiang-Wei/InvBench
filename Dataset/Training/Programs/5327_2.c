#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

/*
 * This program models a simple resource allocation problem where
 * we have a set of resources (modeled by integers), and we allocate
 * them to two tasks. The goal is to make sure that each task does not
 * exceed its resource limit, and overall we do not exceed the total
 * resources available.
 */

typedef struct ResourceAllocator {
    int resource_total;
    int task1_allocated;
    int task2_allocated;
    int task1_limit;
    int task2_limit;
} ResourceAllocator;

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    ResourceAllocator allocator;

    allocator.resource_total = __VERIFIER_nondet_int();
    allocator.task1_limit = __VERIFIER_nondet_int();
    allocator.task2_limit = __VERIFIER_nondet_int();

    // Assumptions for a reasonable setup
    if (!(allocator.resource_total > 0 && allocator.task1_limit > 0 && allocator.task2_limit > 0)) {
        return 0;
    }
    if (!(allocator.task1_limit + allocator.task2_limit <= allocator.resource_total)) {
        return 0;
    }

    allocator.task1_allocated = 0;
    allocator.task2_allocated = 0;

    // Indeterministically allocate resources to tasks
    for (int i = 0; i < allocator.resource_total; i++) {
        if (__VERIFIER_nondet_bool()) {
            if (allocator.task1_allocated < allocator.task1_limit) {
                allocator.task1_allocated++;
            }
        } else {
            if (allocator.task2_allocated < allocator.task2_limit) {
                allocator.task2_allocated++;
            }
        }
    }

    // Ensure allocation respects the limits
    __VERIFIER_assert(allocator.task2_allocated <= allocator.task2_limit);

    return 0;
}