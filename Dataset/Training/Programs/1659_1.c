#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 8, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

/*
Fibonacci-like incremental sum verifier
This program verifies properties for a sequence similar to Fibonacci numbers
*/

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 100); // Assume reasonable bounds for analysis

    int a = 0, b = 1, c;
    int sum = 0;

    // Calculate a Fibonacci-like sequence sum
    for (int i = 0; i < n; i++) {
        c = a + b; // The next Fibonacci number
        a = b;
        b = c;
        sum += a;

        // The following condition checks whether the sum so far is even
        __VERIFIER_assert(sum % 2 == 0 || (a % 2 == 1 && sum % 2 == 1)); // Logical check on parity
    }

    printf("Final sum is %d\n", sum);
    return 0;
}