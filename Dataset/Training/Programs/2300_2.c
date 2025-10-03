#include <stdio.h>
#include <stdlib.h>

void reach_error(void) { abort(); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    // Define condition variables
    int cond1 = __VERIFIER_nondet_int(); // condition variable
    int cond2 = __VERIFIER_nondet_int(); // condition variable
    int cond3 = __VERIFIER_nondet_int(); // condition variable

    // Define lock variables
    int lock1 = 0;
    int lock2 = 0;
    int lock3 = 0;

    // Validation integers
    int sum1 = 0, sum2 = 0, sum3 = 0;
    int limit = __VERIFIER_nondet_int();

    if (limit <= 0) {
        return 0;
    }

    while (1) {
        int loop_cond = __VERIFIER_nondet_int();
        if (loop_cond == 0) {
            break;
        }

        // Reset lock states
        lock1 = 0;
        lock2 = 0;
        lock3 = 0;

        // Conditional lock acquisition
        if (cond1 > 5) {
            lock1 = 1;
        }
        if (cond2 > 5) {
            lock2 = 1;
        }
        if (cond3 > 5) {
            lock3 = 1;
        }

        // Perform some computations when locks are acquired
        if (lock1 == 1) {
            sum1 += cond1;
            if (sum1 >= limit) {
                break;
            }
        }

        if (lock2 == 1) {
            sum2 += cond2;
            if (sum2 >= limit) {
                break;
            }
        }

        if (lock3 == 1) {
            sum3 += cond3;
            if (sum3 >= limit) {
                break;
            }
        }

        // Conditional lock release and validation
        if (lock1 == 1) {
            lock1 = 0; // release lock
        }
        if (lock2 == 1) {
            lock2 = 0; // release lock
            __VERIFIER_assert(sum2 < limit);
        }
        if (lock3 == 1) {
            lock3 = 0; // release lock
        }

        // Simulating external changes in condition variables
        cond1 = __VERIFIER_nondet_int();
        cond2 = __VERIFIER_nondet_int();
        cond3 = __VERIFIER_nondet_int();
    }

    return 0;
}