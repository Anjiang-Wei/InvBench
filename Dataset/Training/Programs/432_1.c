#include <stdbool.h>
#include <stdio.h>

/* Program that simulates a simple banking system where multiple deposits
   are made to an account until a certain goal is reached. The program
   verifies that the balance never exceeds a predefined limit. */

void reach_error(void) {
    printf("Assertion failed!\n");
}

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    const int deposit_limit = 10000; // Max possible balance
    const int num_deposits = 10;     // Number of deposits
    int balance = 0;                 // Initial balance
    int target_balance = 5000;       // Target balance to reach

    // Simulate a sequence of deposits
    for (int i = 0; i < num_deposits; i++) {
        int deposit_amount = __VERIFIER_nondet_int();

        // Ensure deposit amount is non-negative and within a reasonable range
        if (deposit_amount < 0 || deposit_amount > 1000) {
            continue;
        }

        // Update balance and ensure it never exceeds the deposit limit
        balance += deposit_amount;
        if (balance > deposit_limit) {
            reach_error();
            return -1;
        }

        // Check if the target balance is reached
        if (balance >= target_balance) {
            break;
        }
    }

    // Ensure final balance does not exceed limit
    __VERIFIER_assert(balance <= deposit_limit);

    printf("Final Balance: %d\n", balance);
    return 0;
}