#include <stdio.h>
#include <stdlib.h>

// External functions for verification purposes
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
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
    return;
}

int main() {
    int N, LIMIT;
    int sum = 0;
    int i = 0;

    // Non-deterministic input values
    LIMIT = __VERIFIER_nondet_int();
    N = __VERIFIER_nondet_int();

    // Constraints
    assume_abort_if_not(LIMIT > 0);
    assume_abort_if_not(N > 0);

    while (i < LIMIT) {

        sum += i;
        i++;

        if (i >= N) {
            break;
        }
    }

    // Final assertions to be verified
    __VERIFIER_assert(sum == i * (i - 1) / 2 || i == N);

    // Print the final computed sum
    printf("Final sum: %d\n", sum);
    return 0;
}