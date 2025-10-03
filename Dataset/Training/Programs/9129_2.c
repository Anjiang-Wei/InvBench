#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "simple_eq_solver.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

// Function to compute gcd using Euclidean algorithm
int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a = 54;
    int b = 24;
    int result, expected = 6;

    result = gcd(a, b);

    // Verifying the result of the gcd

    // Additional constraints check
    int c = 100;
    int d = 200;
    int sum = 0;
    int n = 10;

    for (int i = 1; i <= n; ++i) {
        sum += i * 2;
    }

    // Ensure that the condition holds
    __VERIFIER_assert(sum == (n * (n + 1)));

    return 0;
}