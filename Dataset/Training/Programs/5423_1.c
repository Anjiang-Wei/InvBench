#include <stdio.h>
#include <stdlib.h>

/*
    Fibonacci Series with Verification
    Computes the Fibonacci sequence iteratively and checks the sum's correctness.
    Uses a loop to calculate terms in the sequence and verifies properties without directly using assertions that indicate loop invariants.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 8, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);
extern void assume_abort_if_not(int cond) {
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
    unsigned int n = __VERIFIER_nondet_uint(); // Fibonacci sequence length
    unsigned int a = 0, b = 1, sum = 0;
    assume_abort_if_not(n > 1 && n < 100); // Assumption on sequence length

    // Calculate n-th Fibonacci number
    unsigned int i;
    for (i = 2; i <= n; i++) {
        unsigned int next = a + b; // Calculate next term
        a = b;
        b = next;
    }

    // Compute sum of Fibonacci series up to n
    a = 0, b = 1;
    for (i = 0; i < n; i++) {
        sum += a;
        unsigned int next = a + b;
        a = b;
        b = next;
    }

    // Verify that the property holds: sum should accommodate n-th Fibonacci term (n = F(n+2) - 1)
    __VERIFIER_assert(sum == b - 1);

    printf("Sum of Fibonacci series up to %u terms is %u\n", n, sum);
    return 0;
}