#include <assert.h>
#include <stdio.h>
extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}
extern int __VERIFIER_nondet_int(void);

// This program simulates a safe bank account system where no account is allowed to go negative.
int main() {
    int accountA = 100;
    int accountB = 100;
    int totalTransactions = 0;
    int maxTransactions = __VERIFIER_nondet_int();

    if (maxTransactions < 0) {
        maxTransactions = 0;
    }

    while (totalTransactions < maxTransactions) {
        int transferAmount = __VERIFIER_nondet_int();

        // Ensure a valid transfer amount
        if (transferAmount < 0) {
            transferAmount = 0;
        }

        int decision = __VERIFIER_nondet_int(); // Decide from which account to transfer
        if (decision % 2 == 0) {
            // Transfer from accountA to accountB
            if (accountA >= transferAmount) {
                accountA -= transferAmount;
                accountB += transferAmount;
            }
        } else {
            // Transfer from accountB to accountA
            if (accountB >= transferAmount) {
                accountB -= transferAmount;
                accountA += transferAmount;
            }
        }

        // Check that no account goes negative
        __VERIFIER_assert(accountA >= 0);

        totalTransactions++;
    }
    printf("All transactions completed.\n");
    return 0;
}