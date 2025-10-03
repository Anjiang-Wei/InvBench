// A C program that calculates Fibonacci numbers and verifies the sum

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 7, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, next, i;
    for (i = 2; i <= n; ++i) {
        next = a + b;
        a = b;
        b = next;
    }
    return b;
}

int main(void) {
    int N = 10; // A safe bound for Fibonacci calculation
    int sum = 0;
    int i;

    for (i = 0; i <= N; ++i) {
        sum += fibonacci(i);
    }

    // Verify if sum of first N Fibonacci numbers is equal to fibonacci(N+2) - 1
    int fib_value = fibonacci(N + 2) - 1;
    __VERIFIER_assert(sum == fib_value);

    return 0;
}