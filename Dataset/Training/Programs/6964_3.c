#include <assert.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void reach_error() { assert(0); }

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
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int sum = 0;
    int increment = 2;

    // Assuming a >= 0 and b >=0 for the context of the problem
    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b >= 0);

    // Compute the sum of the first 'b' even numbers starting from 0
    for (int i = 0; i < b; i++) {
        sum += increment * i;
    }

    // Ensure that sum is even

    // Check if sum is a multiple of 2 * a
    int multiple = a * 2;
    while (__VERIFIER_nondet_bool()) {
        sum += 2;                        // increment sum with an even number
        __VERIFIER_assert(sum % 2 == 0); // Ensure sum always remains even
        if (sum % multiple == 0) {
            break; // Found a sum that is a multiple of 2 * a
        }
    }

    return 0;
}