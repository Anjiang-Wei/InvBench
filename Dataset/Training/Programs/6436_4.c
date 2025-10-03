#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

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

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int x, y, z;
    x = __VERIFIER_nondet_int();
    y = __VERIFIER_nondet_int();
    z = __VERIFIER_nondet_int();

    assume_abort_if_not(x >= 0 && x <= 10);
    assume_abort_if_not(y >= 0 && y <= 10);
    assume_abort_if_not(z >= 0 && z <= 10);

    int a = x, b = y, c = z;
    int sum = 0;
    int i, j = 0;

    // Compute the sum of Fibonacci numbers up to a
    for (i = 0; i <= a; i++) {
        sum += fibonacci(i);
    }

    // Loop to assert some properties
    while (j < 10) {

        // Simple transformation logic
        if (b > c) {
            b -= c;
        } else {
            c -= b;
        }

        if (a % 2 == 0) {
            a /= 2;
        } else {
            a = a * 3 + 1;
        }

        j++;
    }

    // Final assertions
    __VERIFIER_assert(a >= 0);

    return 0;
}