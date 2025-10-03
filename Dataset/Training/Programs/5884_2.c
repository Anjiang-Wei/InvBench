/*
 * New C Program Example
 * This program calculates a simplified Fibonacci sequence and checks
 * if a constraint holds at the end.
 */

#include <stdlib.h>

// Function Prototypes
void reach_error();
void assume_abort_if_not(int cond);
void __VERIFIER_assert(int cond);
extern int __VERIFIER_nondet_int(void);

void reach_error() {
}

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

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0 && N < 50);

    // Fibonacci-like calculation with a modification
    int a = 1, b = 1, temp;

    for (int i = 2; i < N; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }

    // Constraint Check
    if (N > 10) {
        __VERIFIER_assert(b > 50);
    }

    return 0;
}