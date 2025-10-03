#include <assert.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

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
        return -1; // Error condition for negative input
    }
    int result = 1;
    while (n > 1) {
        result *= n;
        n--;
    }
    return result;
}

int main() {
    int n = 5; // Example input
    int fact = factorial(n);

    // Check if factorial(5) = 120

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    // The sum of the first n natural numbers is n * (n + 1) / 2
    __VERIFIER_assert(sum == n * (n + 1) / 2);

    return 0;
}