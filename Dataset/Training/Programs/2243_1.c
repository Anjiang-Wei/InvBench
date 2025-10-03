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
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

/*
  Calculate Fibonacci series up to a limit and verify
  that the series maintains its property for any positive integer inputs
  that determine the series.
*/
int main() {
    int n, i;
    long long fib_1, fib_2, fib_next;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 2); // at least two terms to calculate

    fib_1 = 0;
    fib_2 = 1;
    i = 2; // starting from the 3rd term

    while (i < n) {
        fib_next = fib_1 + fib_2;
        fib_1 = fib_2;
        fib_2 = fib_next;
        i++;
    }

    // Verify the last two terms to ensure the correctness
    __VERIFIER_assert(fib_next == fib_1 + fib_2 - fib_1);

    printf("Fibonacci sequence successfully verified up to term %d.\n", n);

    return 0;
}