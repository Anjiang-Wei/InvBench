// A new C program inspired by the provided examples.

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void __VERIFIER_error(void);
void reach_error() {
    __VERIFIER_error();
    abort();
}
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

int main() {
    int a, b, c;
    long long result;

    // Non-deterministic inputs
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    c = __VERIFIER_nondet_int();

    // Constraints to limit the range of inputs
    assume_abort_if_not(a >= 1 && a <= 100);
    assume_abort_if_not(b >= 1 && b <= 100);
    assume_abort_if_not(c >= 1 && c <= 100);

    // Initial result based on inputs
    result = a + b * c;

    // A loop performing computation and validation
    while (c > 0) {
        // Ensures that result remains above a certain threshold

        // Modify result according to a pattern
        result = result + a - b;

        // Modify c to ensure loop termination
        c = c / 2 + c % 2; // Effectively a decrement that reduces c
    }

    // Final check on the result to ensure its correctness
    __VERIFIER_assert(result > 0 && result <= 10000);

    printf("Final Result: %lld\n", result);

    return 0;
}