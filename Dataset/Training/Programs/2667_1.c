#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);

void reach_error() {
    printf("An error occurred.\n");
    abort();
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    int x = 0, y = 0, z = 1;

    // Ensure `n` is in a reasonable range and is positive
    assume_abort_if_not(n >= 2 && n <= 10000);

    // Arbitrary computation: calculate a form of sequence, such as Fibonacci
    while (n > 0) {
        // Simple transformation logic to mimic computational patterns
        int temp = x;
        x = y;
        y = y + z;
        z = temp;
        n--;

        // Checking some conditions that must hold, similar to invariants
        __VERIFIER_assert(x >= 0);
    }

    // Ensure the end result satisfies a specific condition

    return 0;
}