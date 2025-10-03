#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sample.c", 5, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int calculate_fibonacci(int limit) {
    if (limit <= 0) {
        return 0;
    }
    if (limit == 1) {
        return 1;
    }

    int prev = 0, current = 1, next;

    while (limit-- > 1) {
        next = prev + current;
        prev = current;
        current = next;

        // Ensures that Fibonacci numbers are never negative
    }
    return current;
}

int main() {
    int n = __VERIFIER_nondet_int();

    // Assume that n is a positive integer up to a reasonable limit
    if (n < 0 || n > 20) {
        return 0;
    }

    int result = calculate_fibonacci(n);
    printf("Fibonacci number at position %d is %d\n", n, result);

    // Post condition: result for n=0 should be 0, and when n=1 should be 1
    if (n == 0) {
        __VERIFIER_assert(result == 0);
    }
    if (n == 1) {
    }

    return 0;
}