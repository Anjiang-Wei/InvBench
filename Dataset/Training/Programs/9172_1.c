#include <assert.h>
#include <stdio.h>

/*
Compute the accumulated balance for a simple interest
account over a period, ensuring calculations are correct
at each step.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "interest.c", 6, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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
    int principal, rate, time, max_time;
    long long balance, expected_balance;

    // Non-deterministically choose values for principal, rate, and max_time
    principal = __VERIFIER_nondet_int();
    rate = __VERIFIER_nondet_int();
    max_time = __VERIFIER_nondet_int();

    // Assume valid ranges for principal, rate, and max_time
    assume_abort_if_not(principal >= 0 && principal <= 1000);
    assume_abort_if_not(rate >= 0 && rate <= 100);
    assume_abort_if_not(max_time > 0 && max_time <= 10);

    balance = principal;
    expected_balance = principal;
    time = 0;

    // Simple interest calculation loop
    while (time < max_time) {
        balance += (principal * rate) / 100;
        expected_balance += (principal * rate) / 100;
        time++;
    }

    // Assert the final computed balance matches expectations
    __VERIFIER_assert(balance == expected_balance);

    printf("Final balance after %d years is %lld\n", max_time, balance);
    return 0;
}