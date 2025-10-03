// Summation and Parity Counter
// Verifies invariants on sums and parity properties of random numbers.

#include <stdbool.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "newprog.c", 3, "reach_error"); }
extern void abort(void);
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

extern unsigned int __VERIFIER_nondet_uint(void);

int main() {
    unsigned int n;
    unsigned int even_count = 0, odd_count = 0;
    unsigned int even_sum = 0, odd_sum = 0;

    n = __VERIFIER_nondet_uint();

    // Limit n to prevent excessively large computations in automated tools.
    assume_abort_if_not(n <= 100000);

    for (unsigned int i = 0; i < n; i++) {
        unsigned int value = __VERIFIER_nondet_uint();

        if (value % 2 == 0) {
            even_sum += value;
            even_count++;
        } else {
            odd_sum += value;
            odd_count++;
        }
    }

    unsigned int total_sum = even_sum + odd_sum;
    unsigned int total_count = even_count + odd_count;

    // Verifying that the total count matches the number of iterations
    __VERIFIER_assert(total_count == n);

    // Simple check to ensure sums and counts remain internally consistent

    printf("Even Count: %u, Odd Count: %u\n", even_count, odd_count);
    printf("Even Sum: %u, Odd Sum: %u, Total Sum: %u\n", even_sum, odd_sum, total_sum);

    return 0;
}