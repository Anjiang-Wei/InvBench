#include <assert.h>
#include <limits.h>
#include <stdio.h>

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
    return;
}

int fibonacci(int n) {
    int a = 0, b = 1, fib;
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    while (n-- > 1) {
        fib = a + b;
        a = b;
        b = fib;
    }
    return b;
}

#define LIMIT 15

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= LIMIT);

    int result;
    int expected;

    result = fibonacci(n);
    // Pre-compute expected Fibonacci numbers for the sake of this example
    if (n <= 0) {
        expected = 0;
    } else if (n == 1) {
        expected = 1;
    } else if (n == 2) {
        expected = 1;
    } else if (n == 3) {
        expected = 2;
    } else if (n == 4) {
        expected = 3;
    } else if (n == 5) {
        expected = 5;
    } else if (n == 6) {
        expected = 8;
    } else if (n == 7) {
        expected = 13;
    } else if (n == 8) {
        expected = 21;
    } else if (n == 9) {
        expected = 34;
    } else if (n == 10) {
        expected = 55;
    } else if (n == 11) {
        expected = 89;
    } else if (n == 12) {
        expected = 144;
    } else if (n == 13) {
        expected = 233;
    } else if (n == 14) {
        expected = 377;
    } else if (n == 15) {
        expected = 610;
    }

    __VERIFIER_assert(result == expected);

    return 0;
}