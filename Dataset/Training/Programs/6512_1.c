#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int machines = __VERIFIER_nondet_int();
    int tasks = __VERIFIER_nondet_int();
    int allocation = __VERIFIER_nondet_int();
    int completed_tasks = 0;

    if (!(machines > 0 && tasks > 0 && allocation > 0 && allocation <= machines)) {
        return 0;
    }

    int remaining_tasks = tasks;

    while (remaining_tasks > 0) {
        if (remaining_tasks < allocation) {
            completed_tasks += remaining_tasks;
            remaining_tasks = 0;
        } else {
            completed_tasks += allocation;
            remaining_tasks -= allocation;
        }
        // The while loop ensures completed_tasks are increased correctly
    }

    // Ensure that exactly 'tasks' tasks were completed
    __VERIFIER_assert(completed_tasks == tasks);

    printf("All %d tasks completed using %d machines.\n", tasks, machines);
    return 0;
}