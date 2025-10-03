#include <stdio.h>
#include <stdlib.h>

// External declarations needed for verification
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "stock_trading.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

#define MAX_TRANSACTIONS 1000

int main() {
    int account_balance = 10000; // Initial account balance in dollars
    int stock_price = 100;       // Initial stock price in dollars
    int stocks_owned = 0;
    int transaction_limit = __VERIFIER_nondet_int();

    // Ensure transaction limit is within a safe range
    assume_abort_if_not(transaction_limit > 0 && transaction_limit <= MAX_TRANSACTIONS);

    for (int i = 0; i < transaction_limit; i++) {
        int action = __VERIFIER_nondet_int();   // Choose between 0 (buy) or 1 (sell)
        int quantity = __VERIFIER_nondet_int(); // Quantity to buy/sell

        // Ensure quantity is positive and within a reasonable range
        assume_abort_if_not(quantity >= 0 && quantity <= 100);

        if (action == 0) { // Buy stock
            int cost = stock_price * quantity;
            if (cost <= account_balance) {
                account_balance -= cost;
                stocks_owned += quantity;
            }
        } else { // Sell stock
            if (quantity <= stocks_owned) {
                account_balance += stock_price * quantity;
                stocks_owned -= quantity;
            }
        }

        // Simulate stock price change
        int price_change = __VERIFIER_nondet_int();
        assume_abort_if_not(price_change >= -10 && price_change <= 10);
        stock_price += price_change;

        // Assert that the account balance and stocks owned remain non-negative
    }

    // Assert the final state
    __VERIFIER_assert(stocks_owned >= 0);
    return 0;
}