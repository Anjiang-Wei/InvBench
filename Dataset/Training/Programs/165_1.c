#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* Program Description:
   This program simulates a constrained bank account system.
   The balance should never be below zero and should not exceed a defined upper limit.
*/

int main() {
    int balance = __VERIFIER_nondet_int();
    int upper_limit = 1000; // maximum allowed balance
    int transactions = 10;  // number of transactions to simulate

    // Initial constraint
    if (!(balance >= 0 && balance <= upper_limit)) {
        return 0;
    }

    int transaction_amount;
    for (int i = 0; i < transactions; i++) {
        transaction_amount = __VERIFIER_nondet_int();
        assume_abort_if_not(transaction_amount >= -100 && transaction_amount <= 100); // reasonable transaction range

        // Simulating a deposit or withdrawal
        balance += transaction_amount;

        // Maintain the constraints
        if (balance < 0) {
            balance = 0; // prevent overdraft
        } else if (balance > upper_limit) {
            balance = upper_limit; // cap the balance
        }
    }

    // Post-condition checks
    __VERIFIER_assert(balance >= 0);

    return 0;
}