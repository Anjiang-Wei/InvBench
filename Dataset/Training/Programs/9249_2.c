#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "custom_prog.c", 3, "reach_error");
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

int compute_factorial(int n) {
    if (n < 0) {
        return -1;
    }
    if (n == 0) {
        return 1;
    }
    int res = 1;
    for (int i = 1; i <= n; ++i) {
        res *= i;
    }
    return res;
}

int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int complex_logic(int x, int y) {
    if (x > y) {
        return x - y + 42;
    } else {
        return x + y - 42;
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0 && a < 10);
    assume_abort_if_not(b >= 0 && b < 10);
    assume_abort_if_not(c >= 0 && c < 10);

    int factorial_a = compute_factorial(a);

    int fib_b = fibonacci(b);
    __VERIFIER_assert(fib_b >= 0);

    int complex_result = complex_logic(a, c);

    for (int i = 0; i < 10; ++i) {
        int temp = __VERIFIER_nondet_int();
        assume_abort_if_not(temp >= 0 && temp < 100);
        complex_result += temp;
    }

    return 0;
}