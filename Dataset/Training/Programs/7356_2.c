#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "verification_program.c", 3, "reach_error"); }
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

int FACTOR = 20; // Threshold for complex computations

int main() {
    int N = __VERIFIER_nondet_int();
    int sum = 0;
    int product = 1;

    // Ensuring valid input
    if (N < 1) {
        return 0;
    }

    assume_abort_if_not(N < FACTOR);

    for (int i = 1; i <= N; ++i) {
        sum += i;
        product *= (i % 3 == 0) ? 3 : 1;

        if (i % 2 == 0) {
            sum -= (i / 2);
        }
    }

    __VERIFIER_assert(product > 0);

    return 0;
}