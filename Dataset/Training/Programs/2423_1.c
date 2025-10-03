#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
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
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int M = __VERIFIER_nondet_int();
    assume_abort_if_not(M > 0);

    int a = 2;
    int b = 3;
    long long sum = 0;

    for (int i = 0; i < M; i++) {
        // Calculate the ith term of the sequence
        long long term = (a * i) + b;

        // Add the term to the sum
        sum += term;

        // Update a and b based on some logic
        if (i % 2 == 0) {
            a += 1;
            b -= 1;
        } else {
            a -= 1;
            b += 2;
        }

        // Here, a meaningful computational logic and loop condition are used
        __VERIFIER_assert(sum >= 0); // just ensuring sum doesn't overflow negatively

        // Print the current state (for visualization purposes, not usually in verification)
        printf("i: %d, term: %lld, sum: %lld, a: %d, b: %d\n", i, term, sum, a, b);
    }

    return 0;
}