#include <stdbool.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_problem.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int __VERIFIER_nondet_int() {
    return rand() % 20; // Using rand() for nondeterminism in this example
}

// Function to calculate the factorial of a number
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main(void) {
    int n = __VERIFIER_nondet_int();
    int fact = factorial(n);

    // Assert that if n is negative, factorial should be 1 (since factorial of 0 is 1)
    if (n < 0) {
    } else {
        // Verify a property for small numbers
        if (n <= 5) {
            int expected[] = {1, 1, 2, 6, 24, 120};
            __VERIFIER_assert(fact == expected[n]);
        }
    }

    return 0;
}