#include <stdio.h>
#include <stdlib.h>

// External functions and error handling for verification purposes.
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "example.c", 4, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

extern int __VERIFIER_nondet_int(void);

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, c;

    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int main() {
    int n = __VERIFIER_nondet_int();
    if (n < 0) {
        printf("n must be non-negative\n");
        abort();
    }

    int sum = 0;
    int limit = 10; // limiting the loop for practical verification

    for (int i = 0; i < limit; ++i) {
        if (i == n) {
            break;
        }
        sum += fibonacci(i);
    }

    __VERIFIER_assert(sum >= 0); // The sum of Fibonacci numbers can't be negative.

    printf("Sum of Fibonacci numbers up to term %d (exclusive) is: %d\n", n, sum);

    return 0;
}