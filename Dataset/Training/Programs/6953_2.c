#include <assert.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}
extern int __VERIFIER_nondet_int();

void use_external_resource(int n) {
    // Simulate using an external resource without exceeding a limit
    // In this mock function, we only assert a condition without real effects
}

int main() {
    int limit, usage;
    limit = __VERIFIER_nondet_int();
    usage = 0;

    // Assume the limit to be reasonable within a particular range
    if (limit < 20 || limit > 50) {
        return 0; // Early exit if limit is out of range
    }

    while (1) {
        if (usage >= limit) {
            // Resource usage limit has been reached or exceeded
            __VERIFIER_assert(usage == limit);
            break;
        }

        int consume = rand() % 10; // Simulate consumption between 0 and 9 units
        if (usage + consume <= limit) {
            usage += consume;
            use_external_resource(usage);
        } else {
            // If consumption would exceed limit, do not consume
            // choose whether to consume less or stop loop
            if (usage < limit) {
                usage = limit; // Ensure usage exactly meets the limit
            }
            continue; // Recheck the condition and potentially break
        }
    }

    // Final verification to ensure usage respects the limit boundary

    return 0;
}