/*
 * New Verification Task inspired by previous examples.
 *
 * The program simulates a simplified banking system with verification conditions.
 *
 * Written by AI Assistant, 2023
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "banking.c", __LINE__, "reach_error");
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);
extern unsigned int __VERIFIER_nondet_uint(void);

#define MAX_TRANSACTIONS 100

typedef struct {
    int balance;
} Account;

Account *create_account() {
    Account *acc = (Account *)malloc(sizeof(Account));
    if (!acc) {
        abort();
    }
    acc->balance = 0;
    return acc;
}

void deposit(Account *acc, int amount) {
    assume_abort_if_not(amount >= 0);
    acc->balance += amount;
}

void withdraw(Account *acc, int amount) {
    assume_abort_if_not(amount >= 0);
    if (acc->balance >= amount) {
        acc->balance -= amount;
    }
}

int main() {
    int num_transactions = __VERIFIER_nondet_int();
    assume_abort_if_not(num_transactions > 0 && num_transactions <= MAX_TRANSACTIONS);

    Account *account = create_account();

    for (int i = 0; i < num_transactions; ++i) {
        int operation = __VERIFIER_nondet_int();
        int amount = __VERIFIER_nondet_int();

        assume_abort_if_not(amount >= 0 && amount <= 1000); // Assume reasonable transaction amounts

        if (operation % 2 == 0) {
            deposit(account, amount);
        } else {
            withdraw(account, amount);
        }
    }

    // Verification conditions
    __VERIFIER_assert(account->balance >= 0); // Balance should never be negative

    free(account);
    return 0;
}