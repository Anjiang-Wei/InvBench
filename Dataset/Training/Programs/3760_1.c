#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "verified_avg.c", 8, "reach_error");
}
extern int __VERIFIER_nondet_int(void);
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

int main() {
    int arr[10];
    int sum = 0;
    int n = 10;

    // Initialize the array with nondeterministic values and a constraint
    for (int i = 0; i < n; i++) {
        arr[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(arr[i] >= 0 && arr[i] <= 20); // Constraint between [0, 20]
    }

    // Compute the sum of the array
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // Calculate average
    int avg = sum / n;

    // Choosing a threshold
    int threshold = 10;

    // Verifying that average stays within a range
    if (avg > threshold) {
        __VERIFIER_assert(avg > threshold);
    } else {
    }

    return 0;
}