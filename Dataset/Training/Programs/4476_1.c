#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "proposal.c", 5, "reach_error"); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
    return;
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= 10); // Limit 'n' to reasonable size for the fibonacci calculation

    int fib = 0;
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        fib = fibonacci(i);
        sum += fib;
    }

    // Ensure that sum is a positive number after computation
    __VERIFIER_assert(sum > 0);

    return 0;
}