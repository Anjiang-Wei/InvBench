#include <assert.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

// This program simulates a simple guessing game with a loop
int main() {
    int target = __VERIFIER_nondet_int();
    if (target <= 0) {
        target = 10; // Assume some positive target
    }
    int guess = 0;
    int attempts = 0;

    // Loop until the correct target is guessed or limit is reached
    while (guess != target && attempts < 20) {
        // Generate a non-deterministic guess between 0 and 20
        guess = __VERIFIER_nondet_int();
        if (guess < 0 || guess > 20) {
            continue; // Ignore invalid guesses
        }

        attempts++;

        // Constraint: attempts should always be less than or equal to 20
        __VERIFIER_assert(attempts <= 20);

        if (guess == target) {
            break; // Break the loop once the target is guessed
        }
    }

    // After the loop, either guessed correctly or ran out of attempts

    return 0;
}