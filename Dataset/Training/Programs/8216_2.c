#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() {
    printf("Error reached\n");
    abort();
}
extern int __VERIFIER_nondet_int(void);
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

/* Program Description:
 * This program generates a sequence of Fibonacci numbers and verifies
 * some properties of the sequence. The loop computes Fibonacci numbers
 * until it either reaches a predetermined limit or a certain condition
 * is met.
 */

int main() {
    int limit = 10000; // Limit on Fibonacci value
    int pred;          // Random limit on number of iterations

    // Non-deterministic input
    pred = __VERIFIER_nondet_int();
    assume_abort_if_not(pred >= 0 && pred <= 15);

    int a = 0; // First Fibonacci number
    int b = 1; // Second Fibonacci number
    int next;

    int count = 0;

    while (count < pred && b < limit) {
        __VERIFIER_assert(a >= 0);

        next = a + b;
        a = b;
        b = next;
        count++;
    }

    // Invariants check

    return 0;
}