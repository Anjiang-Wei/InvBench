#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "custom_program.c", 5, "reach_error");
}

extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n < 100);

    int fib_prev = 0;
    int fib_curr = 1;
    int fib_next;

    int i;
    for (i = 2; i < n; i++) {
        fib_next = fib_prev + fib_curr;
        fib_prev = fib_curr;
        fib_curr = fib_next;

        // Ensure the Fibonacci sequence property holds
    }

    // A specific property: The n-th element should be non-negative
    __VERIFIER_assert(fib_curr >= 0);

    printf("Fibonacci number at position %d is: %d\n", n, fib_curr);
    return 0;
}