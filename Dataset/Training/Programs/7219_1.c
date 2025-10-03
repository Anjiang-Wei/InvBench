/*
 * Example C Program Generated
 * The program performs basic arithmetic operations in a loop
 * and ensures that certain constraints are maintained.
 */

#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 5, "reach_error"); }
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
extern int __VERIFIER_nondet_int(void);

// Function to increment and multiply values
int compute(int x) {
    return (x + 3) * 2;
}

int main() {
    int iter_limit = __VERIFIER_nondet_int();
    assume_abort_if_not(iter_limit > 0 && iter_limit <= 1000);

    int y = 0, z = 1, count = 0;
    long long result = 0;

    while (count < iter_limit) {
        if (count % 2 == 0) {
            y += compute(z);
        } else {
            z += compute(y);
        }
        count++;
    }

    result = y + z;

    __VERIFIER_assert(result >= z); // Ensures result is valid
    return 0;
}