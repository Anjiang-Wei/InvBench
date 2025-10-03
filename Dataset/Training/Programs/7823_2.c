#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() {
    printf("Error reached!\n");
    abort();
}
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
extern void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// New program function utilizing the patterns from Example Programs
int main() {
    int x, y, z, result;
    x = __VERIFIER_nondet_int();
    y = __VERIFIER_nondet_int();

    // Provide some constraints
    assume_abort_if_not(x >= 1 && x <= 10);
    assume_abort_if_not(y >= 1 && y <= 10);

    // Initialize result
    result = 0;
    int multiplier = 1;

    // A loop to mimic a series expansion computation
    for (int i = 0; i < y; i++) {
        result += x * multiplier;
        multiplier *= 2; // Exponential growth pattern

        // Verify that result is consistent with expected computation
    }

    // Final check after loop
    __VERIFIER_assert(result == x * ((1 << y) - 1));

    printf("Computation finished without errors: result = %d\n", result);

    return 0;
}