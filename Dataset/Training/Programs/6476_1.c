#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom.c", 5, "reach_error"); }
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

// The program performs operations analogous to a bank transaction model
// assuming interest accumulations periodically with restrictions on withdrawals

typedef struct {
    int balance;
    int interest_rate; // percentage points per cycle
    int allowed_withdrawal_limit;
} Account;

Account *create_account(int initial_balance, int interest_rate, int withdrawal_limit) {
    Account *account = malloc(sizeof(Account));
    if (!account) {
        abort(); // Prevent null pointer usage
    }
    account->balance = initial_balance;
    account->interest_rate = interest_rate;
    account->allowed_withdrawal_limit = withdrawal_limit;

    return account;
}

void simulate_cycles(Account *acc, int cycles) {
    int cycle = 0;
    while (cycle < cycles) {
        // At the beginning of each cycle, interest is applied
        acc->balance += (acc->balance * acc->interest_rate) / 100;

        // Random withdrawal amount
        int withdrawal = __VERIFIER_nondet_int();
        assume_abort_if_not(withdrawal >= 0);

        // Check for allowed withdrawal condition and update balance if permitted
        if (withdrawal <= acc->allowed_withdrawal_limit && withdrawal <= acc->balance) {
            acc->balance -= withdrawal;
        }

        // Verify that the balance doesn't go negative after all operations
        __VERIFIER_assert(acc->balance >= 0);

        cycle++;
    }
}

int main() {
    Account *acc;
    int initial_balance = __VERIFIER_nondet_int();
    int interest_rate = __VERIFIER_nondet_int();
    int allowed_withdrawal_limit = __VERIFIER_nondet_int();
    int cycles = __VERIFIER_nondet_int();

    assume_abort_if_not(initial_balance >= 0);
    assume_abort_if_not(interest_rate >= 0 && interest_rate <= 100);
    assume_abort_if_not(allowed_withdrawal_limit >= 0);
    assume_abort_if_not(cycles >= 0);

    acc = create_account(initial_balance, interest_rate, allowed_withdrawal_limit);

    simulate_cycles(acc, cycles);

    // Free allocated memory
    free(acc);

    return 0;
}