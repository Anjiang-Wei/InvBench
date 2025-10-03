#include <stdio.h>
#include <stdlib.h>

// Prototype declarations for error handling and non-deterministic functions
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Internal assertion function
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int M, N, sum = 0, product = 1;

    // Non-deterministic choices for M and N
    M = __VERIFIER_nondet_int();
    N = __VERIFIER_nondet_int();

    assume_abort_if_not(M > 0 && M < 100); // Assumptions on the value of M
    assume_abort_if_not(N > 0 && N < 100); // Assumptions on the value of N

    // Loop invariants can be analyzed independently by verification tools
    for (int i = 1; i <= M; i++) {
        sum += i;
        product *= i;
        __VERIFIER_assert(product > 0); // To ensure no integer overflow

        if (sum > 1000) {
            break; // Early exit if sum exceeds threshold
        }
    }

    printf("Computed sum: %d\n", sum);
    printf("Computed product: %d\n", product);
}