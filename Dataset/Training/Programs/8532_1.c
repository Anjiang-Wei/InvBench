#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_example.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    // Initialize variables with deterministic values
    int sum = 0;
    int n = 10; // This can be any number we want to compute the sum up to
    int i = 0;

    // Using a loop to compute the sum of the first n natural numbers
    while (i <= n) {
        sum += i;
        i++;
    }

    // Let's introduce some constraints for verification
    // The sum of first n natural numbers is given by the formula n*(n+1)/2
    int expected_sum = n * (n + 1) / 2;

    // Check that our computed sum matches the expected sum
    __VERIFIER_assert(sum == expected_sum);

    // Output the result
    printf("Sum of the first %d natural numbers is: %d\n", n, sum);
    return 0;
}