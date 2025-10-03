#include <stdio.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void reach_error(void) {
    printf("Error reached\n");
    abort();
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
This program simulates a simple banking transaction system where:
- An initial balance is given.
- A series of deposits and withdrawals are performed.
- The final balance should match the expected final balance calculated.
*/

int main() {
    int balance = __VERIFIER_nondet_int();
    int expected_balance = balance;
    if (!(balance >= 0)) {
        return 0; // Precondition: balance must be non-negative
    }

    int transaction;
    unsigned int number_of_transactions = __VERIFIER_nondet_uint();

    unsigned int counter = 0;
    while (counter < number_of_transactions) {
        transaction = __VERIFIER_nondet_int();

        // Random positive or negative transaction amount
        balance += transaction;

        // Update expected_balance accordingly
        expected_balance += transaction;

        // Condition to keep balance non-negative

        // Move to the next transaction
        counter++;
    }

    // Ensure that the calculated balance matches the expected balance
    __VERIFIER_assert(balance == expected_balance);

    return 0;
}