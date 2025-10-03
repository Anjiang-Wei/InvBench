#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
 * This program attempts to simulate a simple banking process
 * where a user's balance is increased by depositing an amount,
 * and a loop simulates multiple deposits. After all deposits,
 * it verifies if the account balance is within expected limits.
 */

int main() {
    int balance = __VERIFIER_nondet_int();
    int n_deposits = __VERIFIER_nondet_int();
    int max_deposit = __VERIFIER_nondet_int();

    // Preconditions
    if (!(balance >= 0 && n_deposits > 0 && max_deposit >= 0)) {
        return 0;
    }
    if (n_deposits > 100) {
        n_deposits = 100; // Assume a cap on number of deposits
    }

    int total_deposited = 0;
    int i = 0;

    while (i < n_deposits) {
        int deposit = __VERIFIER_nondet_int();
        if (deposit < 0) {
            deposit = 0; // No negative deposits allowed
        }
        if (deposit > max_deposit) {
            deposit = max_deposit; // Cap each deposit
        }

        balance += deposit;
        total_deposited += deposit;
        i++;
    }

    // Postcondition
    __VERIFIER_assert(balance >= total_deposited);
}