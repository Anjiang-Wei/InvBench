#include <stdio.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "banking.c", 9, "reach_error"); }

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

#define MAX_ACCOUNTS 2
#define MAX_BALANCE 10000

typedef struct {
    int balance;
} Account;

Account accounts[MAX_ACCOUNTS];

void deposit(int account, int amount) {
    // Ensure deposit is reasonable
    assume_abort_if_not(account >= 0 && account < MAX_ACCOUNTS);
    assume_abort_if_not(amount > 0);
    assume_abort_if_not(accounts[account].balance + amount <= MAX_BALANCE);

    accounts[account].balance += amount;
}

void withdraw(int account, int amount) {
    // Ensure withdrawal is reasonable
    assume_abort_if_not(account >= 0 && account < MAX_ACCOUNTS);
    assume_abort_if_not(amount > 0);
    assume_abort_if_not(accounts[account].balance >= amount);

    accounts[account].balance -= amount;
}

void transfer(int from, int to, int amount) {
    // Ensure transfer is reasonable
    assume_abort_if_not(from >= 0 && from < MAX_ACCOUNTS);
    assume_abort_if_not(to >= 0 && to < MAX_ACCOUNTS);
    assume_abort_if_not(amount > 0);
    assume_abort_if_not(accounts[from].balance >= amount);
    assume_abort_if_not(accounts[to].balance + amount <= MAX_BALANCE);

    accounts[from].balance -= amount;
    accounts[to].balance += amount;
}

int main() {
    // Initialize accounts
    accounts[0].balance = __VERIFIER_nondet_int();
    accounts[1].balance = __VERIFIER_nondet_int();

    assume_abort_if_not(accounts[0].balance >= 0 && accounts[0].balance <= MAX_BALANCE);
    assume_abort_if_not(accounts[1].balance >= 0 && accounts[1].balance <= MAX_BALANCE);

    while (1) {
        int operation = __VERIFIER_nondet_int();

        if (operation == 1) {
            int account = __VERIFIER_nondet_int();
            int amount = __VERIFIER_nondet_int();
            deposit(account, amount);
        } else if (operation == 2) {
            int account = __VERIFIER_nondet_int();
            int amount = __VERIFIER_nondet_int();
            withdraw(account, amount);
        } else if (operation == 3) {
            int from = __VERIFIER_nondet_int();
            int to = __VERIFIER_nondet_int();
            int amount = __VERIFIER_nondet_int();
            transfer(from, to, amount);
        } else {
            // Invalid operation
            break;
        }

        // Assert that balances are within limits
        __VERIFIER_assert(accounts[0].balance >= 0 && accounts[0].balance <= MAX_BALANCE);
    }

    return 0;
}