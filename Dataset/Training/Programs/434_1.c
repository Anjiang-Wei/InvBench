#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 6, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int calculate_series(int n) {
    int sum = 0;
    int current = 1;
    for (int i = 0; i < n; i++) {
        sum += current;
        current *= 2; // Exponentially growing sequence
    }
    return sum;
}

int main() {
    int N = __VERIFIER_nondet_int();

    // Assuming N must be positive for this computation
    assume_abort_if_not(N > 0 && N < 100); // Providing a bound for demonstration

    int result = calculate_series(N);

    // Logically verify that result is a series sum
    // In a formal sense, this would be: result == (2^N - 1), but we won't assert this directly
    printf("Computed series sum for N=%d: %d\n", N, result);

    // Verify boundary condition (placeholder for analytical tools)
    __VERIFIER_assert(result > 0);

    return 0;
}