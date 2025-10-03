/*
Fibonacci Sequence Generator and Parity Checker
Computes the Fibonacci sequence up to the nth element and checks parity conditions.
*/

#include <stdio.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci_parity.c", 9, "reach_error"); }
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

int is_even(int num) {
    return (num % 2 == 0);
}

int main() {
    int n;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0); // n must be non-negative

    int a = 0, b = 1, next;
    int i = 0;

    // Parity initialization
    int even_count = 0, odd_count = 0;

    while (i < n) {
        // Compute the next Fibonacci number
        next = a + b;
        a = b;
        b = next;

        // Check parity and count
        if (is_even(next)) {
            even_count++;
        } else {
            odd_count++;
        }

        i++;
    }

    // At this point, odd_count should equal or exceed even_count for Fib sequence
    __VERIFIER_assert(odd_count >= even_count);

    // Parity totals should sum to the nth Fibonacci

    printf("Fibonacci sequence up to the %d-th element calculated.\n", n);
    printf("Even count: %d, Odd count: %d\n", even_count, odd_count);

    return 0;
}