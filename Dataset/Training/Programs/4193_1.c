#include <assert.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "prog.c", 6, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

/*
 * Example program with meaningful computation and constraints
 * Simulates simple banking account management with deposits and withdrawals
 */
int main() {
    int balance, deposit, withdrawal;
    int maxTransactions, transactions = 0;

    balance = __VERIFIER_nondet_int();
    maxTransactions = __VERIFIER_nondet_int();
    assume_abort_if_not(balance >= 0);
    assume_abort_if_not(maxTransactions > 0 && maxTransactions <= 1000);

    while (transactions < maxTransactions && balance >= 0) {
        if (__VERIFIER_nondet_bool()) {
            // Perform a deposit
            deposit = __VERIFIER_nondet_int();
            assume_abort_if_not(deposit > 0);
            balance = balance + deposit;
        } else {
            // Perform a withdrawal
            withdrawal = __VERIFIER_nondet_int();
            assume_abort_if_not(withdrawal > 0);
            if (balance >= withdrawal) {
                balance = balance - withdrawal;
            }
            // only allow viable withdrawals to avoid overdraft
        }

        transactions++;
    }

    // Check that after all valid transactions, the balance is left as non-negative
    __VERIFIER_assert(balance >= 0);

    return 0;
}