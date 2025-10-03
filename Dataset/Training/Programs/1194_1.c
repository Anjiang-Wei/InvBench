#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci_verification.c", 5, "reach_error"); }

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
    int n, i;
    unsigned long long a, b, c;

    // Let's assume n is a positive number, within valid bounds
    n = 20; // You can modify this value as per your choice
    assume_abort_if_not(n >= 0);

    a = 0;
    b = 1;
    i = 0;

    // Compute Fibonacci series iteratively until n
    while (i < n) {
        c = a + b;
        a = b;
        b = c;
        i++;
    }

    // Verify the final value: Fibonacci(20) should be 6765 if n is 20
    __VERIFIER_assert((n != 20) || (a == 6765));

    printf("Fibonacci number at position %d is %llu\n", n, a);
    return 0;
}