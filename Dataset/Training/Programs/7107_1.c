#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

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
}

// This program models a simple resource allocation problem
// where `a` and `b` are resource requests constrained between limits

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int limit = 150; // total available resource

    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b >= 0);
    assume_abort_if_not(a <= 100);
    assume_abort_if_not(b <= 100);

    int allocation_a = 0;
    int allocation_b = 0;

    // Attempt to allocate resources to a and b within the limit
    while (allocation_a + allocation_b < limit) {
        _Bool add_to_a = __VERIFIER_nondet_bool();

        if (add_to_a && allocation_a < a) {
            allocation_a++;
        } else if (!add_to_a && allocation_b < b) {
            allocation_b++;
        }

        // Break the loop if no more allocations can be done within requested limits
        if (allocation_a == a && allocation_b == b) {
            break;
        }
    }

    // Post condition: allocated resources should not exceed limits
    __VERIFIER_assert(allocation_a <= a);

    return 0;
}