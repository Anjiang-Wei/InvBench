#include <assert.h>
#include <stdio.h>

extern void abort(void);
void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int counter = 0;
    int max_limit = 100;
    int min_limit = -100;
    int input;

    while (1) {
        input = __VERIFIER_nondet_int();

        // Simulating input constraints
        if (input < -1 || input > 1) {
            continue; // Only allow input of -1, 0, or 1
        }

        if (input == 1) {
            counter += 1;
        } else if (input == -1) {
            counter -= 1;
        }

        // Assert that counter stays within the limits
        __VERIFIER_assert(counter <= max_limit && counter >= min_limit);

        // Exit condition for demonstration purposes
        if (counter == max_limit || counter == min_limit) {
            break;
        }
    }

    printf("Counter reached a limit: %d\n", counter);
    return 0;
}