#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "fib_verify.c", 5, "reach_error");
}
extern int __VERIFIER_nondet_int(void);
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

int main() {
    int n, i;
    long long int fib1, fib2, fib_next;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 30);

    fib1 = 0;
    fib2 = 1;

    if (n == 0) {
    } else if (n == 1) {
    } else {
        for (i = 2; i <= n; ++i) {
            fib_next = fib1 + fib2;

            __VERIFIER_assert(fib_next >= fib2); // Fibonacci property
            __VERIFIER_assert(fib_next >= fib1); // Fibonacci property

            fib1 = fib2;
            fib2 = fib_next;
        }

        // Verify that fib(n) is indeed the n-th Fibonacci number (implicitly affecting memory)
    }

    return 0;
}