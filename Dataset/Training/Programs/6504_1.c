#include <assert.h>

extern void abort(void);
void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

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
    int m = 0, n = 0;
    int limit = __VERIFIER_nondet_int();

    // Precondition: limit is assumed positive for the loop to eventually terminate appropriately
    assume_abort_if_not(limit > 0 && limit < 1000); // limit should be within a reasonabne range

    while (__VERIFIER_nondet_bool()) {
        if (m < limit) {
            m += 2; // Increment m by 2
        } else {
            n += 3; // Increment n by 3
        }

        // Break condition to ensure no infinite loop
        if (n > 10 * limit) {
            break;
        }
    }

    // Postcondition: m is no more than double the limit, or n exceeds limit * 10.
    __VERIFIER_assert((m <= limit * 2) || (n > limit * 10));

    return 0;
}