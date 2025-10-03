#include <assert.h>
#include <stdio.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
    return;
}

/*
  Program to compute Fibonacci sequence
  and verify its properties using assertions.
*/
int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 46); // Limiting input to prevent overflow

    int a = 0, b = 1, c, i;

    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 0;
    }

    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    // Verify the computed Fibonacci number using properties
    // Property: Fibonacci sequence grows monotonically
    __VERIFIER_assert(c >= a && c >= b);

    // Printing the result for clarity (can be removed in verification context)
    printf("Fibonacci(%d) = %d\n", n, c);

    return 0;
}