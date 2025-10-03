#include <stdio.h>

extern void abort(void);
void reach_error() {
    printf("Error reached\n");
    abort();
}
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/**
 * This program models a simple financial transaction system
 * where transfers between two accounts should not result
 * in negative balances.
 */
int main() {
    int balanceA = __VERIFIER_nondet_int();
    int balanceB = __VERIFIER_nondet_int();

    // Initial conditions
    assume_abort_if_not(balanceA >= 0 && balanceA <= 1000);
    assume_abort_if_not(balanceB >= 0 && balanceB <= 1000);

    int transfer_limit = __VERIFIER_nondet_int();

    // Transfer limit condition
    assume_abort_if_not(transfer_limit >= 0 && transfer_limit <= 500);

    while (__VERIFIER_nondet_int()) {
        int transfer_amount = __VERIFIER_nondet_int();

        // Transfer amount condition
        assume_abort_if_not(transfer_amount >= 0 && transfer_amount <= transfer_limit);

        // Simulating transfer from account A to account B
        if (balanceA >= transfer_amount) {
            balanceA -= transfer_amount;
            balanceB += transfer_amount;
        }

        // Assertion to check that the balances stay non-negative
        __VERIFIER_assert(balanceA >= 0 && balanceB >= 0);
    }

    // Final condition - assumption: total balance doesn't exceed an initial max
    assume_abort_if_not(balanceA + balanceB <= 2000);

    printf("Final balances: A = %d, B = %d\n", balanceA, balanceB);

    return 0;
}