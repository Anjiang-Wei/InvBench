#include <stdio.h>

// Function declarations for aborting and assertions
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "sum_of_squares.c", 8, "reach_error"); }

// Function for generating non-deterministic integer
extern int __VERIFIER_nondet_int(void);

// Function to simulate assertion failures
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

// Function to handle aborted conditions
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int k, n;
    long long sum, c;

    // Non-deterministically choose values for k and n
    k = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    // Assume k and n are positive
    assume_abort_if_not(k > 0);
    assume_abort_if_not(n > 0);

    sum = 0;
    c = 1;

    while (c <= k) {
        c++;
    }

    // Additional check: Compare the calculated sum with a given number n
    __VERIFIER_assert(sum <= n);

    // Output the sum
    printf("Sum of squares is: %lld\n", sum);

    return 0;
}