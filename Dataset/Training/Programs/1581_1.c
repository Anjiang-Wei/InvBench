#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 5, "reach_error"); }

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

int main() {
    int n = 10; // We can use a known value for demonstration
    int sum = 0;
    int i;

    // Accumulate the sum of the first n even numbers
    for (i = 0; i < n; i++) {
        sum += 2 * i;
    }

    // Simple condition to verify: the sum of the first n even numbers is n*(n-1)
    __VERIFIER_assert(sum == n * (n - 1));

    // Output the result
    printf("Sum of the first %d even numbers is: %d\n", n, sum);

    return 0;
}