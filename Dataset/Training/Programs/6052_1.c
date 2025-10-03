#include <stdbool.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "fibonacci.c", 5, "reach_error");
}
extern int __VERIFIER_nondet_int(void);

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
    int n = __VERIFIER_nondet_int();

    // Limit the range of n for demonstration purposes
    assume_abort_if_not(n >= 0 && n <= 20);

    int fib[n + 1];
    fib[0] = 0;
    if (n > 0) {
        fib[1] = 1;
    }

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        // Prevent overflow check
        assume_abort_if_not(fib[i] >= 0);
    }

    // Check if the final calculated Fibonacci number is correct
    if (n >= 0) {
        __VERIFIER_assert(fib[n] >= 0);
    }

    printf("Fibonacci of %d is %d\n", n, fib[n]);

    return 0;
}