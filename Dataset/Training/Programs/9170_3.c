#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_example.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int();
extern _Bool __VERIFIER_nondet_bool();

// Simulating a resource management system with 3 resources
// and dynamic allocation based on random conditions

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    int r1_alloc = 0, r2_alloc = 0, r3_alloc = 0;                // Allocation counters
    int r1_threshold = 10, r2_threshold = 15, r3_threshold = 20; // Allocation thresholds
    int r1_consumed = 0, r2_consumed = 0, r3_consumed = 0;       // Consumed counters

    _Bool allocate_more = __VERIFIER_nondet_bool();

    // Simulating a loop for dynamic resource allocation and consumption
    while (allocate_more) {
        int demand1 = __VERIFIER_nondet_int() % 3;
        int demand2 = __VERIFIER_nondet_int() % 5;
        int demand3 = __VERIFIER_nondet_int() % 7;

        if (r1_alloc + demand1 <= r1_threshold) {
            r1_alloc += demand1;
        }
        if (r2_alloc + demand2 <= r2_threshold) {
            r2_alloc += demand2;
        }
        if (r3_alloc + demand3 <= r3_threshold) {
            r3_alloc += demand3;
        }

        // By probabilistically determining to consume some resources
        if (__VERIFIER_nondet_bool()) {
            r1_consumed += r1_alloc / 2;
            r2_consumed += r2_alloc / 2;
            r3_consumed += r3_alloc / 2;

            r1_alloc /= 2;
            r2_alloc /= 2;
            r3_alloc /= 2;

            // Printing the current state of resource consumption and allocation
            printf("Resources Allocated: r1=%d, r2=%d, r3=%d\n", r1_alloc, r2_alloc, r3_alloc);
            printf("Resources Consumed: r1=%d, r2=%d, r3=%d\n", r1_consumed, r2_consumed, r3_consumed);
        }

        allocate_more = __VERIFIER_nondet_bool();
    }

    // Verifying that no more resources were allocated than the threshold
    __VERIFIER_assert(r3_alloc <= r3_threshold);

    printf("Verification passed. Resource management logic executed as expected.\n");
    return 0;
}