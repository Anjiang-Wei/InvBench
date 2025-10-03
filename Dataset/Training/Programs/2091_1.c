#include <assert.h>
#include <stdio.h>

// External functions that typically represent nondeterministic behaviors.
extern void abort(void);
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool();

void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int compute_fibonacci_until(int threshold) {
    int a = 0, b = 1, c = 1;

    while (c <= threshold) {
        int next = a + b;
        a = b;
        b = next;
        c++;

        // Verify the Fibonacci sequence progression
        __VERIFIER_assert(b >= a);
    }
    return b;
}

int main() {
    int threshold;

    // Obtain a nondeterministic threshold value
    threshold = __VERIFIER_nondet_int();
    if (threshold < 1) {
        threshold = 1; // Ensure the threshold is positive
    }

    int result = compute_fibonacci_until(threshold);

    // Final check to ensure results are within logical constraints

    // Return the final result
    printf("Resulting Fibonacci number: %d\n", result);
    return 0;
}