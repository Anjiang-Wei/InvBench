// This program calculates the Fibonacci sequence up to a certain number, but with added constraints
// and properties suitable for verification purposes. The program includes assertions to check
// properties of the sequence.

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 6, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int max_value = __VERIFIER_nondet_int();

    // Let's assume some reasonable constraint for verification purposes
    if (max_value < 0 || max_value > 10) {
        exit(0);
    }

    int a = 0, b = 1;
    int i = 0;

    // Loop to calculate Fibonacci sequence up to max_value
    while (i < max_value) {
        int next = a + b;
        a = b;
        b = next;
        i++;

        // Assertion to check the known property of Fibonacci numbers
        // Every Fibonacci number is less than or equal to 2^(n-1)
        // This will hold for smaller numbers and is useful for verification
        __VERIFIER_assert(a <= (1 << (i - 1)));

        // Additional safety checks
        if (a < 0) { // Overflow check (though practically unreachable in this range)
            { reach_error(); }
            abort();
        }
    }

    return 0;
}