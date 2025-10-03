#include <assert.h>
#include <stdbool.h>

void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR:
        reach_error();
    }
    return;
}

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
    assume_abort_if_not(n >= 0 && n <= 10); // Limiting n for simplicity and tool analysis

    int fib_n = fibonacci(n);
    int fib_n_minus_one = (n > 0) ? fibonacci(n - 1) : 0;
    int fib_n_minus_two = (n > 1) ? fibonacci(n - 2) : 0;

    // Verify that fib(n) = fib(n-1) + fib(n-2) for n > 1
    if (n > 1) {
        __VERIFIER_assert(fib_n == fib_n_minus_one + fib_n_minus_two);
    }

    return 0;
}