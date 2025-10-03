/*
 * New C program designed for verification and analysis by automated tools.
 * This program simulates a simple banking system where transactions are made
 * on accounts, and assertions are made to ensure correctness of balances.
 */

#include <stdlib.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "banking.c", 10, "reach_error");
}

extern int __VERIFIER_nondet_int();
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

#define MAX_TRANSACTIONS 100

typedef struct {
    int id;
    int balance;
} Account;

void transfer(Account *from, Account *to, int amount) {
    if (from->balance >= amount) {
        from->balance -= amount;
        to->balance += amount;
    }
}

int main() {
    Account a1 = {1, 1000};
    Account a2 = {2, 1500};

    int i;
    int num_transactions = __VERIFIER_nondet_int();
    assume_abort_if_not(num_transactions >= 1 && num_transactions <= MAX_TRANSACTIONS);

    for (i = 0; i < num_transactions; i++) {
        int amount = __VERIFIER_nondet_int();
        assume_abort_if_not(amount >= 0 && amount <= 100);

        if (__VERIFIER_nondet_int() % 2 == 0) {
            transfer(&a1, &a2, amount);
        } else {
            transfer(&a2, &a1, amount);
        }
    }

    // Verify that the overall balance doesn't change
    __VERIFIER_assert(a1.balance + a2.balance == 2500);

    return 0;
}