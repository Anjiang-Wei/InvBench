// SPDX-License-Identifier: Apache-2.0
//
// This program implements a simple simulated banking system with an overdraft protection feature.
// Account balance and transaction operations are checked to avoid the overdraft limit being exceeded.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "bank.c", 6, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

#define OVERDRAFT_LIMIT -500

int main() {
    int balance = 0;                       // Initial balance
    int overdraft_limit = OVERDRAFT_LIMIT; // Overdraft protection limit

    while (1) {
        int transaction = __VERIFIER_nondet_int(); // Non-deterministic transaction amount

        // Apply transaction if it doesn't violate overdraft limit
        if (balance + transaction >= overdraft_limit) {
            balance += transaction;
        }

        __VERIFIER_assert(balance >= overdraft_limit); // Ensure overdraft limit is never violated
    }

    return 0;
}