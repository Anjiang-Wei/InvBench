// Fibonacci sequence calculation with verification of constraints
#include <limits.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 3, "reach_error"); }
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
    int a = 0, b = 1, temp, n;
    n = __VERIFIER_nondet_int(); // Allow any integer input for n

    assume_abort_if_not(n >= 0 && n < 47); // Prevent overflow in Fibonacci sequence within usual int range

    int counter = 0, i = 0;

    while (counter++ < 1) {
        if (n == 0) {
            printf("Fibonacci sequence number at position %d is: %d\n", n, a);
            return 0;
        } else if (n == 1) {
            printf("Fibonacci sequence number at position %d is: %d\n", n, b);
            return 0;
        }

        for (i = 2; i <= n; ++i) {
            temp = b;
            b = a + b;
            a = temp;
            // Avoid overflow, since b should not exceed the maximum value of int
        }

        __VERIFIER_assert(b >= a); // Asserting standard property of Fibonacci
        printf("Fibonacci sequence number at position %d is: %d\n", n, b);
    }

    return 0;
}