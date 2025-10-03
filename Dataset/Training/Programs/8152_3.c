#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Function to simulate a verification tool's assumption of non-deterministic input
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void reach_error() {
    // Function to simulate an error report
    printf("Verification failed.\n");
    abort();
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0);

    int poise = 1;
    long long balance = 0;

    // Simulate a series of transactions with specific rules
    for (int i = 0; i < n; i++) {
        int amount = __VERIFIER_nondet_int();
        assume_abort_if_not(amount >= 0);

        balance += amount;

        if (balance >= 1000) {
            poise += 1;
            // Spend part of the balance when it gets too high
            balance -= 100;
        }
    }

    // Ensuring post-conditions are met
    // A meaningful post-condition related to our logic
    __VERIFIER_assert(poise <= n + 1);

    return 0;
}