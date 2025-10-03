#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "prog.c", 4, "reach_error"); }
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
}

int balance = 0;
int transactions[5] = {100, -200, 300, -150, 50}; // Daily transactions: deposits (positive) and withdrawals (negative)

void make_transaction(int amount) {
    balance += amount;
}

int main() {
    int day = 0;
    int overdraft_limit = -100; // Balance cannot go below -100

    while (day < 5) {
        make_transaction(transactions[day]);

        // Verify that balance never goes beyond the overdraft limit
        __VERIFIER_assert(balance >= overdraft_limit);

        day++;
    }

    // Check if the final balance is reasonable
    int expected_final_balance = 100;

    return 0;
}