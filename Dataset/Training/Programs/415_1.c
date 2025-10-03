// This program demonstrates a simple bank account simulation
// with deposit and withdrawal operations, while maintaining
// balance constraints.

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

int main() {
    int balance = 0;
    int deposit, withdrawal;
    int iterations = 5; // Number of transactions

    while (iterations > 0) {
        __VERIFIER_assert(balance >= 0); // Balance should never be negative

        // Random nondeterministic value for deposit
        deposit = rand() % 100;

        // Perform deposit
        if (deposit > 0) {
            balance += deposit;
        }

        // Random nondeterministic value for withdrawal
        withdrawal = rand() % 50;

        // Perform withdrawal
        if (withdrawal <= balance) {
            balance -= withdrawal;
        }

        printf("Current balance: %d\n", balance);

        // Assurance that balance doesn't exceed a threshold for this simulation.
        if (balance > 500) {
            printf("Balance exceeded threshold, stopping simulation.\n");
            break;
        }

        iterations--;
    }

    // Final balance check

    printf("Simulation completed with final balance: %d\n", balance);

    return 0;
}