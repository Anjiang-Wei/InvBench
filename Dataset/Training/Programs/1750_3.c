#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 3, "reach_error"); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int __VERIFIER_nondet_int(void);

/* This function computes Fibonacci numbers iteratively */
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n = __VERIFIER_nondet_int();

    // Ensure n is non-negative and within reasonable bounds
    assume_abort_if_not(n >= 0 && n <= 30);

    int computed_fib = fibonacci(n);

    // Manually check a few base values to ensure correctness:
    if (n == 0) {
    } else if (n == 1) {
    } else if (n == 5) {
        __VERIFIER_assert(computed_fib == 5);
    }

    printf("Fibonacci(%d) = %d\n", n, computed_fib);

    return 0;
}