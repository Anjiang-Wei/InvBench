#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR:
        reach_error();
    }
    return;
}

int compute_factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * compute_factorial(n - 1);
}

int main() {
    int m, result, temp;
    m = __VERIFIER_nondet_int();
    assume_abort_if_not(m >= 1 && m <= 10);

    // Initial computations
    result = 0;
    temp = 3; // Starting with a non-zero initial value

    // The loop to apply some operations
    for (int i = 1; i <= m; i++) {
        temp *= 2;      // Exponentially increase temp
        result += temp; // Accumulate result
    }

    // Perform some operations outside the loop for verification
    int factorial_result = compute_factorial(m);

    // Asserting different properties at the end, but not a loop invariant
    __VERIFIER_assert(factorial_result > 0);

    return 0;
}