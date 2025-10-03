// A C program to simulate simple banking transactions
// and ensure account balances never go negative

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "bank.c", 5, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

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

#define MAX_TRANSACTIONS 1000

typedef struct {
    int balance;
} Account;

void deposit(Account *acc, int amount) {
    acc->balance += amount;
}

void withdraw(Account *acc, int amount) {
    if (acc->balance >= amount) {
        acc->balance -= amount;
    }
}

int main() {
    Account account1;
    account1.balance = __VERIFIER_nondet_int();
    assume_abort_if_not(account1.balance >= 0);

    Account account2;
    account2.balance = __VERIFIER_nondet_int();
    assume_abort_if_not(account2.balance >= 0);

    int transaction_count = 0;
    int amount;

    while (transaction_count < MAX_TRANSACTIONS) {
        if (__VERIFIER_nondet_bool()) {
            amount = __VERIFIER_nondet_int();
            assume_abort_if_not(amount >= 0);
            deposit(&account1, amount);
        } else if (__VERIFIER_nondet_bool()) {
            amount = __VERIFIER_nondet_int();
            assume_abort_if_not(amount >= 0);
            withdraw(&account1, amount);
        } else if (__VERIFIER_nondet_bool()) {
            amount = __VERIFIER_nondet_int();
            assume_abort_if_not(amount >= 0);
            deposit(&account2, amount);
        } else {
            amount = __VERIFIER_nondet_int();
            assume_abort_if_not(amount >= 0);
            withdraw(&account2, amount);
        }

        transaction_count++;

        __VERIFIER_assert(account1.balance >= 0);
    }

    return 0;
}