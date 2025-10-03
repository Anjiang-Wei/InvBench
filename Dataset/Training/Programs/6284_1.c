#include <assert.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "proposed-program.c", 6, "reach_error"); }

extern unsigned int __VERIFIER_nondet_uint(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

typedef struct {
    unsigned int current_balance;
    unsigned int max_balance;
} BankAccount;

int main() {
    // Define a bank account with an initial balance and a max limit
    BankAccount account;
    account.current_balance = 0;
    account.max_balance = 5000;

    // Define a counter for transactions applied
    unsigned int transaction_count = 0;
    unsigned int max_transactions = 100;

    // Define transaction amounts to deposit
    unsigned int deposit = __VERIFIER_nondet_uint();

    while (transaction_count < max_transactions) {
        // Avoid overflow in current balance
        if (account.current_balance + deposit > account.max_balance) {
            break; // Stop if deposit would exceed max balance
        }

        // Deposit the amount into the account
        account.current_balance += deposit;

        // Increment transaction count
        transaction_count++;
    }

    // Verify final condition
    __VERIFIER_assert(account.current_balance <= account.max_balance);

    // Exit successfully
    return 0;
}