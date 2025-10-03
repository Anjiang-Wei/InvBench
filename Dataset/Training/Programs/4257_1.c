#include <limits.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 7, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int global_counter = 0;

int main() {
    int balance = 0;
    int deposit, withdrawal;

    deposit = __VERIFIER_nondet_int();
    withdrawal = __VERIFIER_nondet_int();

    // Ensure deposit and withdrawal are within a certain range
    if (deposit < 0 || deposit > 1000) {
        return 0;
    }
    if (withdrawal < 0 || withdrawal > 1000) {
        return 0;
    }

    while (global_counter < 10) {
        balance += deposit;
        if (balance < 0) {
            balance = 0; // Cannot go below 0
        }

        if (balance < withdrawal) {
            withdrawal = balance; // Avoid negative balance
        }

        balance -= withdrawal;

        __VERIFIER_assert(balance >= 0);

        global_counter++;
    }

    printf("Final balance: %d\n", balance);
    return 0;
}