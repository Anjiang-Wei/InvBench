/*
  Program that simulates a simple banking system to ensure balances are updated correctly.
  The program has checks to prevent over-withdrawal, maintains balance constraints and accumulates interest.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "banking.c", 7, "reach_error"); }
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

int counter = 0;
int main() {
    int initial_balance, withdrawal, deposit, interest_rate, final_balance;
    initial_balance = __VERIFIER_nondet_int();
    withdrawal = __VERIFIER_nondet_int();
    deposit = __VERIFIER_nondet_int();
    interest_rate = __VERIFIER_nondet_int();

    assume_abort_if_not(initial_balance >= 0);
    assume_abort_if_not(withdrawal >= 0);
    assume_abort_if_not(deposit >= 0);
    assume_abort_if_not(interest_rate >= 0 && interest_rate <= 100);

    int balance = initial_balance;

    // Processing a series of 10 transactions
    while (counter++ < 10) {
        // Withdraw funds if sufficient balance
        if (balance >= withdrawal) {
            balance -= withdrawal;
        }

        // Deposit some funds
        balance += deposit;

        // Apply a simple interest
        balance += (balance * interest_rate) / 100;

        // Ensure balance never becomes negative
        if (balance < 0) {
            reach_error();
        }
    }

    final_balance = balance;

    // Ensure final balance is non-negative
    __VERIFIER_assert(final_balance >= 0);

    return 0;
}