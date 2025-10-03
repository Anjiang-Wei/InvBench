#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "myprogram.c", 3, "reach_error"); }
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
    int balance, monthly_deposit, yearly_interest, goal;
    int year = 0;
    int target_year;

    balance = __VERIFIER_nondet_int();
    monthly_deposit = __VERIFIER_nondet_int();
    yearly_interest = __VERIFIER_nondet_int();
    goal = __VERIFIER_nondet_int();
    target_year = __VERIFIER_nondet_int();

    // Assumptions for the bounds and conditions
    assume_abort_if_not(balance >= 0);
    assume_abort_if_not(monthly_deposit >= 0);
    assume_abort_if_not(yearly_interest >= 0);
    assume_abort_if_not(goal > 0);
    assume_abort_if_not(target_year > 0);

    while (1) {
        // Calculate yearly balance with monthly deposits and yearly interest
        balance = balance + 12 * monthly_deposit;
        balance = balance + (balance * yearly_interest) / 100;
        year++;

        // Break conditions
        if (year >= target_year || balance >= goal) {
            break;
        }
    }

    // Verification assertion
    __VERIFIER_assert(balance >= 0);
    return 0;
}