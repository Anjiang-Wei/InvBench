#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "bank_system.c", 8, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

// Bank account structure
typedef struct {
    int balance;
    int max_balance;
    int min_balance;
} BankAccount;

// Function to perform a transaction
int perform_transaction(BankAccount *account, int amount) {
    int new_balance = account->balance + amount;
    if (new_balance > account->max_balance || new_balance < account->min_balance) {
        return -1; // Transaction would exceed constraints
    }
    account->balance = new_balance;
    return 0; // Transaction successful
}

int main() {
    BankAccount account;
    account.balance = __VERIFIER_nondet_int();
    account.max_balance = 1000; // Max balance constraint
    account.min_balance = -500; // Min balance (overdraft) constraint

    assume_abort_if_not(account.balance >= account.min_balance && account.balance <= account.max_balance);

    int transactions = __VERIFIER_nondet_int();
    assume_abort_if_not(transactions >= 0 && transactions <= 100);

    int i;
    for (i = 0; i < transactions; i++) {
        int transaction_amount = __VERIFIER_nondet_int();
        assume_abort_if_not(transaction_amount >= -200 && transaction_amount <= 200);

        int result = perform_transaction(&account, transaction_amount);
    }

    __VERIFIER_assert(account.balance >= account.min_balance && account.balance <= account.max_balance);

    return 0;
}