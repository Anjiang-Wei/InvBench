#include <stdint.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 6, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main(void) {
    int count = 0;
    int target_sum = __VERIFIER_nondet_int();
    assume_abort_if_not(target_sum >= 1 && target_sum <= 100);
    int sum = 0;
    int step = 5;
    int steps_taken = 0;

    // Loop with a non-trivial constraint
    while (sum < target_sum) {
        if (step + sum <= target_sum) {
            sum += step;
            steps_taken++;
        } else {
            step--; // Reduce step if it overshoots the target
        }

        // Safety condition: sum should never exceed target_sum
        count++;
        if (count >= 25) {
            break; // Artificial bound to prevent infinite loops
        }
    }

    // Assert that the sum has reached the target or could not proceed further
    __VERIFIER_assert(sum >= target_sum || step == 0);
    printf("Reached sum: %d with steps taken: %d\n", sum, steps_taken);
    return 0;
}