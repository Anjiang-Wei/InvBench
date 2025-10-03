/*
 * This program simulates a banking transaction scenario where a user can transfer money between two accounts
 * and performs checks to ensure that the transactions are consistent.
 */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "transaction-verifier.c", 8, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);
extern void abort(void);
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
    unsigned int initial_balance_1, initial_balance_2;
    unsigned int transaction_1_to_2, transaction_2_to_1;

    initial_balance_1 = __VERIFIER_nondet_uint();
    initial_balance_2 = __VERIFIER_nondet_uint();
    transaction_1_to_2 = __VERIFIER_nondet_uint();
    transaction_2_to_1 = __VERIFIER_nondet_uint();

    // Assume initial balances are realistic and transactions <= balances
    assume_abort_if_not(initial_balance_1 >= transaction_1_to_2);
    assume_abort_if_not(initial_balance_2 >= transaction_2_to_1);

    unsigned int balance_1 = initial_balance_1;
    unsigned int balance_2 = initial_balance_2;

    int iteration_limit = 5; // Simulate a loop where up to 5 transactions are possible
    int i = 0;

    while (i < iteration_limit) {
        if (i % 2 == 0) {
            balance_1 -= transaction_1_to_2;
            balance_2 += transaction_1_to_2;
        } else {
            balance_2 -= transaction_2_to_1;
            balance_1 += transaction_2_to_1;
        }
        i++;
    }

    // Check if the total balance is invariant
    __VERIFIER_assert((balance_1 + balance_2) == (initial_balance_1 + initial_balance_2));

    return 0;
}