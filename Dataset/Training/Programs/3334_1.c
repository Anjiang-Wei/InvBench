#include <assert.h>
#include <stdbool.h>

void reach_error() { assert(0); }
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
}

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
    // Initialize two variables
    int m = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();

    // Assumptions to keep values in a defined range
    assume_abort_if_not(m >= 0);
    assume_abort_if_not(n >= 0);
    assume_abort_if_not(m < 10); // Restricting to avoid large numbers
    assume_abort_if_not(n < 10); // Restricting to avoid large numbers

    // Calculate the Fibonacci sequence up to m
    int fib_m = fibonacci(m);

    // Another computationally meaningful task: Determine sum of first n natural numbers
    int sum_n = 0;
    for (int i = 1; i <= n; i++) {
        sum_n += i;
    }

    // Verify some conditions at the end
    __VERIFIER_assert(fib_m >= 0);

    return 0;
}