#include <stdio.h>
#include <stdlib.h>

// Function to simulate an assertion failure
void reach_error() {
    printf("Error: Constraint violated\n");
    abort();
}

// Function to check if a condition is true, else reach an error
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Function to simulate a non-deterministic integer input
int __VERIFIER_nondet_int(void) {
    return rand() % 100; // Returns a random number between 0 and 99
}

// Simulate banking transactions
typedef struct {
    int balance;
    int transaction_limit;
} Account;

void perform_transactions(Account *account) {
    int transactions = __VERIFIER_nondet_int() % 20; // Number of transactions
    for (int i = 0; i < transactions; i++) {
        int amount = __VERIFIER_nondet_int() % 50; // Transaction amount
        int type = __VERIFIER_nondet_int() % 2;    // 0 for deposit, 1 for withdrawal

        if (type == 0) {
            // Deposit
            int new_balance = account->balance + amount;
        } else {
            // Withdrawal
            if (account->balance >= amount) {
                account->balance -= amount;
            }
        }

        // Check if transaction limit is exceeded
        __VERIFIER_assert(account->balance <= account->transaction_limit);
    }
}

int main(void) {
    Account account;
    account.balance = 100;           // Initial balance
    account.transaction_limit = 200; // Maximum allowed balance

    perform_transactions(&account);

    // Verify post-condition: balance should never exceed transaction limit

    printf("Final Balance: %d\n", account.balance);
    return 0;
}