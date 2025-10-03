#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 6, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int factorial(int n) {
    if (n < 0) {
        return -1; // Invalid for negative
    }
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int compute_series(int size) {
    if (size > 10) {
        return -1; // Constraint to make verification feasible
    }
    int sum = 0;
    for (int i = 1; i <= size; i++) {
        sum += factorial(i);
    }
    return sum;
}

int main() {
    int n = 5; // You can also set it as a nondet value limited by constraints
    if (n < 1 || n >= 10) {
        __VERIFIER_assert(0); // Invalid conditions produce an error
    }

    int result = compute_series(n);
    int expected_value = 34; // The result for n=5 should be 34 (1!+2!+3!+4!+5!)

    return 0;
}