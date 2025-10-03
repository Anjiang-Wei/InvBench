#include <assert.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error(void) { __assert_fail("0", "custom_program.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

// Function to calculate the sum of the first n natural numbers
int sum_natural_numbers(int n) {
    int sum = 0;
    int i = 1;
    while (i <= n) {
        sum = sum + i;
        i++;
    }
    return sum;
}

// Function to calculate the factorial of a number
int factorial(int n) {
    if (n < 0) {
        return 0; // Invalid case
    }
    int result = 1;
    int i;
    for (i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main(void) {
    int n = __VERIFIER_nondet_int();
    int m = __VERIFIER_nondet_int();

    assume_abort_if_not(n >= 0);
    assume_abort_if_not(m >= 0 && m < 20); // To prevent overflow in factorial

    int sum = sum_natural_numbers(n);
    int fact = factorial(m);

    // Known properties
    __VERIFIER_assert(sum >= 0);
}