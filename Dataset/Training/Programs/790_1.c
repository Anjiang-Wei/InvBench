/*
  A program that models a simple banking transaction system
  using a loop to simulate a series of deposits and withdrawals.
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "bank_transaction.c", 7, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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

int main() {
    int balance, transaction, iterations;
    balance = __VERIFIER_nondet_int();
    assume_abort_if_not(balance >= 0 && balance <= 10000); // starting balance between 0 and 10000

    iterations = __VERIFIER_nondet_int();
    assume_abort_if_not(iterations >= 0 && iterations <= 1000); // number of transactions between 0 and 1000

    int i = 0;
    while (i < iterations) {
        transaction = __VERIFIER_nondet_int();
        assume_abort_if_not(transaction >= -500 && transaction <= 500); // transaction amount between -500 and 500

        if (transaction < 0) {
            // Withdrawal
            if (balance + transaction >= 0) { // Ensure balance does not go negative
                balance += transaction;
            }
        } else {
            // Deposit
            balance += transaction;
        }

        // Check that the balance is never negative
        __VERIFIER_assert(balance >= 0);

        i++;
    }

    // Final assertion to ensure the balance is within expected range after transactions

    printf("Final balance: %d\n", balance);
    return 0;
}