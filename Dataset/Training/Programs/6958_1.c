#include <assert.h>
#include <stdlib.h>

// Error reporting function
void reach_error(void) { assert(0); }

// Assertion function to be checked by a verifier
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// External functions simulating nondeterministic inputs
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int sum_of_even_fibonacci(int limit) {
    if (limit <= 0) {
        return 0;
    }

    // Initialize the first two Fibonacci numbers
    int a = 0, b = 1;
    int sum = 0;

    // Iterate over Fibonacci sequence
    while (b <= limit) {
        if (b % 2 == 0) {
            sum += b; // Add to sum if the number is even
        }
        int next = a + b;
        a = b;
        b = next;
    }
    return sum;
}

// Main function applying verification
int main() {
    int N = __VERIFIER_nondet_int();

    // Limit range to meaningful values
    assume_abort_if_not(N >= 1 && N <= 1000000);

    // Calculate the sum of even Fibonacci numbers up to N
    int result = sum_of_even_fibonacci(N);

    // Check if the result is non-negative
    __VERIFIER_assert(result >= 0);

    // Assume that result consists only of even Fibonacci numbers

    return 0;
}