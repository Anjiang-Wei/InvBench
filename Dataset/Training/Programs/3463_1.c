#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }
extern int __VERIFIER_nondet_int(void);
extern void __VERIFIER_assume(int);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
Program Description:
- This program models a basic bank transaction system.
- The bank balance `balance` starts at an unknown but determinedly non-negative value.
- Random withdrawals `amount` are made while the balance allows.
- The loop ensures the balance never goes negative by assuming valid transactions.
- The program verifies that certain conditions hold after each transaction.
- Meaningful checks: Make sure the `balance` stays valid.
*/

int main() {
    int balance = __VERIFIER_nondet_int();
    __VERIFIER_assume(balance >= 0);

    int transaction_counter = 0;

    while (1) {
        int amount = __VERIFIER_nondet_int();
        __VERIFIER_assume(amount > 0);

        if (balance >= amount) {
            balance -= amount;
        } else {
            // Imagine this as a situation where the transaction is declined
            break;
        }

        transaction_counter++;
        __VERIFIER_assert(balance >= 0); // Ensures at every point balance is non-negative
    }

    // Ensure valid stopping state
    __VERIFIER_assert(transaction_counter >= 0);
    return 0;
}