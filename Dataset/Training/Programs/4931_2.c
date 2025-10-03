#include <stdio.h>
#include <stdlib.h>

/* This program implements a simple simulation of resource allocation
 * for a system with multiple resources. It checks for potential deadlocks
 * using a basic resource request-reward algorithm.
 */

extern int __VERIFIER_nondet_int(void);
void reach_error(void) { __assert_fail("0", "new_program.c", 3, "reach_error"); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

int main() {
    const int MAX_RESOURCES = 10;
    const int MAX_REQUESTS = 20;

    // Simulated number of available resources
    int available_resources = 5;
    int allocated_resources = 0;              // Resources currently allocated
    int max_demand = __VERIFIER_nondet_int(); // Maximum demand of resources

    assume_abort_if_not(max_demand >= 0 && max_demand <= MAX_RESOURCES);

    int i;
    for (i = 0; i < MAX_REQUESTS; ++i) {
        int request = __VERIFIER_nondet_int();
        assume_abort_if_not(request >= 0 && request <= MAX_RESOURCES);

        if (request + allocated_resources <= max_demand &&
            request <= available_resources) {
            // Allocate requested resources
            allocated_resources += request;
            available_resources -= request;
        } else {
            // Request currently denied
        }

        if (allocated_resources == max_demand || available_resources == 0) {
            // Simulate releasing resources
            available_resources += allocated_resources;
            allocated_resources = 0;
        }
    }

    __VERIFIER_assert(available_resources + allocated_resources <= MAX_RESOURCES);

    return 0;
}