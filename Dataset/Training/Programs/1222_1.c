#include <stdio.h>
#include <stdlib.h>

/* A program to simulate a simple task scheduler */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "task_scheduler.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    // Simulate task durations and a rudimentary scheduler

    int tasks_remaining = __VERIFIER_nondet_int(); // Number of pending tasks
    int time_quantum = 5;                          // Time slice for each task, can be tuned
    int total_time_spent = 0;
    int task_duration;

    if (tasks_remaining < 1) {
        // No tasks to schedule
        printf("No tasks to schedule.\n");
        return 0;
    }

    while (tasks_remaining > 0) {
        task_duration = __VERIFIER_nondet_int(); // Nondeterministic task duration

        if (task_duration <= 0) {
            // Invalid or non-positive task duration, skip this task
            tasks_remaining--;
            continue;
        }

        if (task_duration <= time_quantum) {
            // Task can be completed in one time slice
            tasks_remaining--;
            total_time_spent += task_duration;
        } else {
            // Task takes more than one time slice
            tasks_remaining--;
            total_time_spent += time_quantum;

            // Simulate adding the unfinished portion of this task back into the task queue
            tasks_remaining++;
        }

        // Basic condition check: total time spent should always be positive
        __VERIFIER_assert(total_time_spent > 0);
    }

    printf("All tasks complete. Total time spent: %d\n", total_time_spent);
    return 0;
}