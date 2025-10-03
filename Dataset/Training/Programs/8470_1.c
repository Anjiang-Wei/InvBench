#include <stdio.h>
#include <stdlib.h>

// Function prototypes for verification tools
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "bank_simulation.c", 3, "reach_error"); }
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
    int balance, limit, transactions;
    int deposit, withdrawal;
    int counter = 0;

    balance = 1000;                  // Initial balance
    limit = __VERIFIER_nondet_int(); // Maximum number of transactions
    assume_abort_if_not(limit > 0);  // Ensure limit is positive

    transactions = 0;

    while (counter++ < 100 && transactions < limit) {
        // Assume some operation is possible
        if (__VERIFIER_nondet_int() % 2 == 0) {
            deposit = __VERIFIER_nondet_int();
            assume_abort_if_not(deposit >= 0); // Deposits must be non-negative
            balance += deposit;
        } else {
            withdrawal = __VERIFIER_nondet_int();
            assume_abort_if_not(withdrawal >= 0); // Withdrawals must be non-negative
            if (withdrawal <= balance) {
                balance -= withdrawal;
            }
        }

        transactions++;
    }

    // Ensure balance remains non-negative after transactions
    __VERIFIER_assert(balance >= 0);

    printf("Final balance: %d\n", balance);
    printf("Total transactions processed: %d\n", transactions);

    return 0;
}