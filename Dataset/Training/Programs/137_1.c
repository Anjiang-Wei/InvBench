#include <stdio.h>
#include <stdlib.h>

// Externally defined functions for error handling
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 4, "reach_error"); }

// Function to handle assumptions that lead to abort if not met
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Function with a specific error condition to stop execution
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

// Main function with meaningful computational logic
int main() {
    int balance = 1000; // Start with a balance of 1000
    int withdrawal, deposit;

    // Seed the random number generator for nondeterministic behavior
    srand(0);

    // Loop with specified conditions
    while (balance > 0) {
        // Simulate random transactions
        withdrawal = rand() % 201; // Withdrawals ranging from 0 to 200
        deposit = rand() % 151;    // Deposits ranging from 0 to 150

        // Apply withdrawal and deposit logic
        balance = balance - withdrawal; // Withdraw from balance
        balance = balance + deposit;    // Deposit into balance

        // Condition: ensure balance cannot go below zero
        if (balance < 0) {
            balance = 0; // Reset balance to zero if negative
        }

        // Assert statement to check invariants and prevent errors
        __VERIFIER_assert(balance >= 0);

        // Break condition: exit the loop if balance is zero
        if (balance == 0) {
            break;
        }
    }

    // Exit program successfully if loop completes
    return 0;
}