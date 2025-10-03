#include <stdio.h>
#include <stdlib.h>

// Define some constants for constraints
#define MAX_BALANCE 10000
#define MIN_BALANCE 0
#define TRANSACTION_LIMIT 1000

// Function prototypes
void reach_error();
void __VERIFIER_assert(int cond);
int calculate_interest(int balance);
int execute_transaction(int *balance, int amount);

void reach_error() {
    printf("Error: A constraint has been violated.\n");
    exit(EXIT_FAILURE);
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int calculate_interest(int balance) {
    // Simple interest calculation based on balance range
    if (balance < 1000) {
        return balance * 0.01;
    } else if (balance < 5000) {
        return balance * 0.02;
    } else {
        return balance * 0.03;
    }
}

int execute_transaction(int *balance, int amount) {
    // Check constraints before executing the transaction
    if (amount > TRANSACTION_LIMIT) {
        printf("Transaction amount exceeds the limit.\n");
        return -1;
    }
    if (*balance + amount > MAX_BALANCE) {
        printf("Transaction would exceed maximum balance.\n");
        return -1;
    }
    if (*balance + amount < MIN_BALANCE) {
        printf("Transaction would result in negative balance.\n");
        return -1;
    }

    // Execute the transaction
    *balance += amount;
    return 0;
}

int main() {
    int balance = 500; // Initial balance

    for (int i = 0; i < 5; i++) {                                                      // Loop to simulate multiple transactions
        int transaction_amount = rand() % (2 * TRANSACTION_LIMIT) - TRANSACTION_LIMIT; // Random transaction value
        printf("Transaction %d: Attempting to change balance by %d\n", i + 1, transaction_amount);

        // Execute transaction and assert balance constraints
        int result = execute_transaction(&balance, transaction_amount);
        if (result == 0) {
            printf("Transaction successful. New balance: %d\n", balance);
        } else {
            printf("Transaction failed.\n");
        }

        // Calculate interest after the transaction
        int interest = calculate_interest(balance);
        printf("Calculated interest: %d\n", interest);

        // Verify constraints using assertions
        __VERIFIER_assert(balance >= MIN_BALANCE && balance <= MAX_BALANCE);
    }

    printf("Final balance: %d\n", balance);

    return 0;
}