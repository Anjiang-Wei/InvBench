#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }

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
        return -1; // Error case for negative input
    }
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
        assume_abort_if_not(result > 0); // Overflow check
    }
    return result;
}

int compute_fibonacci(int n) {
    if (n < 0) {
        return -1; // Error case for negative input
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        assume_abort_if_not(c > b); // Overflow check
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int input = __VERIFIER_nondet_int();

    // Constraint for input range
    assume_abort_if_not(input >= 0 && input <= 20);

    // Compute factorial
    int factorial_result = compute_factorial(input);

    // Compute fibonacci
    int fibonacci_result = compute_fibonacci(input);

    // Check specific conditions
    if (input >= 10) {
    } else {
        __VERIFIER_assert(fibonacci_result <= 6765); // Fibonacci(20) is 6765
    }

    return 0;
}