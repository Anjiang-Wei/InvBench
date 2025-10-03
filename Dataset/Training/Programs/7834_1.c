#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { __assert_fail("0", "factorial_verification.c", 3, "reach_error"); }
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int N = __VERIFIER_nondet_int();
    if (N < 0) {
        return 1; // Factorial not defined for negative numbers
    }

    unsigned long long factorial = 1;
    unsigned long long expected_factorial = 1; // Example: Change this to a known value for testing

    // Predefined known value for testing, e.g., factorial(5) = 120.
    if (N == 5) {
        expected_factorial = 120;
    }

    for (int i = 1; i <= N; i++) {
        factorial *= i;
    }

    if (N == 5) {                                           // Only perform the assertion check for N = 5
        __VERIFIER_assert(factorial == expected_factorial); // Check if calculated factorial matches
    }

    return 0;
}