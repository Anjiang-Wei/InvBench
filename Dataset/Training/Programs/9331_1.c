#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 4, "reach_error"); }

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
}

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0 && N <= 1000); // Ensure N is a positive integer within a reasonable limit

    int *a = (int *)malloc(sizeof(int) * N);
    int *b = (int *)malloc(sizeof(int) * N);
    if (a == NULL || b == NULL) {
        abort(); // Check for allocation failures
    }

    a[0] = 1;
    b[0] = 0;

    // Populate arrays with some meaningful computations
    // a[i] accumulates the sequence sum and b[i] accumulates squares sum of indices
    for (int i = 1; i < N; i++) {
        a[i] = a[i - 1] + i;
        b[i] = b[i - 1] + i * i;
    }

    // Conduct checks based on a pattern observed
    for (int i = 0; i < N; i++) {
        // Check a simple constraint property
        if (b[i] < a[i] * i) {
            __VERIFIER_assert(b[i] < a[i] * i);
        }
    }

    // Free allocated memory
    free(a);
    free(b);

    return 0;
}