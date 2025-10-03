#include <limits.h>

extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sample-program.c", 4, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    int a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        int temp = b;
        b = a + b;
        a = temp;
    }
    return b;
}

int main() {
    int n = __VERIFIER_nondet_int();
    if (n < 0 || n > 10) {
        return 0; // assuming a safe range for n
    }

    int expected_fib = fibonacci(n);

    int a = 0, b = 1, fib = 0;
    int i = 0;

    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 0;
    }

    while (i < n - 1) {
        fib = a + b;
        a = b;
        b = fib;
        i++;
    }

    __VERIFIER_assert(fib == expected_fib);

    return 0;
}