#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom.c", 3, "reach_error"); }
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

// Definition of MAX_SIZE for controlling nondeterministic loop bounds
#define MAX_SIZE 50000

unsigned int __VERIFIER_nondet_uint();
int main() {
    unsigned int n, i, j, sum_i = 0, sum_j = 0;
    n = __VERIFIER_nondet_uint();
    // Assume the size is within a reasonable and verifiable bound
    assume_abort_if_not(n <= MAX_SIZE);

    i = 1;
    j = 1;

    // Simultaneous sequences computation using a loop
    while (i < n && j < n) {
        sum_i += i * i;     // Square of i
        sum_j += j * j + j; // Sum of j square and j

        i = i * 2; // Doubling the index
        j = j + 3; // Incrementing the index by 3
    }

    // Assert a simple arithmetic property on the calculated sums
    __VERIFIER_assert((sum_i + sum_j) % 2 == (sum_i % 2 + sum_j % 2));

    printf("Computation completed with sum_i: %u, sum_j: %u\n", sum_i, sum_j);
    return 0;
}