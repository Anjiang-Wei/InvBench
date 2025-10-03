#include <assert.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);

// This is a simulated function for testing purposes
int __VERIFIER_nondet_int() {
    // Simulate a non-deterministic integer, e.g., a random value
    // For demonstration, return a fixed value to avoid randomness in this example
    return 10;
}

int main(void) {
    int n = __VERIFIER_nondet_int();
    int i = 0;
    int sum = 0;

    if (n <= 0) {
        return 0; // Ensure n is a positive number
    }

    while (i < n) {
        sum += i * 2; // A computation step
        i++;
    }

    __VERIFIER_assert(sum >= 0); // Ensure sum is non-negative

    printf("Sum of first %d even numbers: %d\n", n, sum);
    return 0;
}