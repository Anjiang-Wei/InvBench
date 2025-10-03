#include <assert.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "gen_program.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main(void) {
    int balance = 100;                            // Starting balance
    int transactions[5] = {10, -20, -30, 40, 10}; // A sequence of transactions
    int i = 0;

    while (i < 5) {
        balance += transactions[i];
    }

    // Final check (should not trigger)
    __VERIFIER_assert(balance == 110);

    return 0;
}