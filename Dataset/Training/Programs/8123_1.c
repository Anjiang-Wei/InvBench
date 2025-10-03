#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 5, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

extern int __VERIFIER_nondet_int(void);

// This program simulates a basic banking system
// with deposits and withdrawals while maintaining a balance limit
int main() {
    int balance = 0;
    int max_limit = 10000; // maximum allowable balance
    int transaction;

    while (__VERIFIER_nondet_int()) {
        transaction = __VERIFIER_nondet_int();

        // Assuming transaction can be deposit (positive) or withdrawal (negative)
        if (transaction < 0) {
            // Withdrawal: check for sufficient balance
            if (balance + transaction >= 0) {
                balance += transaction;
            }
        } else {
            // Deposit: check for balance limit
            if (balance + transaction <= max_limit) {
                balance += transaction;
            }
        }

        // Invariant: The balance should never go negative and should not exceed the max limit
        __VERIFIER_assert(balance >= 0 && balance <= max_limit);
    }

    return 0;
}