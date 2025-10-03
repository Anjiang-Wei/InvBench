#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
void reach_error(void) {
    abort();
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
}

// This program models a system with a safety-critical constraint
// The system keeps track of resource allocation and must balance resources by the end

int main() {
    int a = __VERIFIER_nondet_int(); // resource a
    int b = __VERIFIER_nondet_int(); // resource b
    int total_resources = 1000;      // assumed total resources
    int threshold = 200;             // minimum resource allocation to terminate

    if (a < 0 || b < 0 || a + b > total_resources) {
        return 0;
    }

    // Resource balancing process
    while (a < threshold) {
        int allocation = __VERIFIER_nondet_int();
        if (allocation < 0 || a + allocation > total_resources) {
            continue; // invalid allocation, try again
        }

        a += allocation;
        b -= allocation;

        // Simulate a critical operation that must not drop below zero
        if (b < 0) {
            b = 0; // correcting for safety
        }
    }

    __VERIFIER_assert(a + b <= total_resources);

    printf("Resource balancing complete: a=%d, b=%d\n", a, b);

    return 0;
}