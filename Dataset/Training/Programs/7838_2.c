// New C Program Example

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 4, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
Fibonacci Sequence Calculation
Computes the nth Fibonacci number iteratively.
Ensures that the computed value matches the expected value for small sequences.
*/
int main() {
    int n = __VERIFIER_nondet_int();
    if (n < 0 || n > 10) {
        return 0; // Limit the input range for verification
    }

    int a = 0, b = 1, temp, i;

    if (n == 0) {
        return 0;
    }

    for (i = 1; i < n; ++i) {
        temp = a + b;
        a = b;
        b = temp;
    }

    // Here, b should be the nth Fibonacci number
    int fib_expected_values[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55}; // For n from 0 to 10
    __VERIFIER_assert(b == fib_expected_values[n]);

    return 0;
}