#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
 * This program simulates a banking system where three accounts have initial
 * non-negative balances. A transfer operation randomly chooses two accounts
 * and transfers a random positive amount between them, as long as the
 * transferring account has enough balance. The loop goes on until a random
 * condition stops the transactions or one of the accounts' balance reaches zero.
 */

int main() {
    int account1 = __VERIFIER_nondet_int();
    int account2 = __VERIFIER_nondet_int();
    int account3 = __VERIFIER_nondet_int();
    int temp; // Temporary variable for transfer operations

    // Precondition: All accounts must have non-negative balances.
    if (!(account1 >= 0 && account2 >= 0 && account3 >= 0)) {
        return 0;
    }

    while (__VERIFIER_nondet_bool()) {
        int transfer_amount = __VERIFIER_nondet_int();
        int choice = __VERIFIER_nondet_int() % 3;

        // Ensure transfer_amount is a positive number
        if (transfer_amount <= 0) {
            continue;
        }

        switch (choice) {
        case 0: // Transfer from account1 to account2
            if (account1 >= transfer_amount) {
                account1 -= transfer_amount;
                account2 += transfer_amount;
            }
            break;
        case 1: // Transfer from account2 to account3
            if (account2 >= transfer_amount) {
                account2 -= transfer_amount;
                account3 += transfer_amount;
            }
            break;
        case 2: // Transfer from account3 to account1
            if (account3 >= transfer_amount) {
                account3 -= transfer_amount;
                account1 += transfer_amount;
            }
            break;
        default:
            break;
        }

        // Break if any account balance becomes zero (constraint condition)
        if (account1 == 0 || account2 == 0 || account3 == 0) {
            break;
        }
    }

    // Postcondition: At least one of the accounts should have non-zero balance
    __VERIFIER_assert(account1 >= 0 && account2 >= 0 && account3 >= 0);
    return 0;
}