#include <assert.h>
#include <stdbool.h>

void reach_error() { assert(0); }
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
    return;
}

int main() {
    int total_work = __VERIFIER_nondet_int();
    assume_abort_if_not(total_work >= 10 && total_work <= 100);

    int work_done = 0;
    int reward = 0;

    while (work_done < total_work) {
        // Increment the work done by a random amount each iteration
        int increment = __VERIFIER_nondet_int();
        assume_abort_if_not(increment > 0 && increment <= 10);

        work_done += increment;
        if (work_done > total_work) {
            work_done = total_work;
        }

        // Apply a reward logic: increase reward based on work_done so far
        reward += increment * 2;
    }

    // Verify that after completing the work, one condition should be met
    __VERIFIER_assert(work_done == total_work && reward >= total_work * 2);

    return 0;
}