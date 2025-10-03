#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Fibonacci Series
Calculates the Fibonacci sequence up to the nth term.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 8, "reach_error"); }
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

int main() {
    int n, i;
    int *fibonacci_sequence;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n < 50); // reasonable bounds to keep calculations safe

    if (n == 0) {
        return 0; // trivial case
    }

    fibonacci_sequence = (int *)malloc((n + 1) * sizeof(int));
    if (fibonacci_sequence == NULL) {
        return 1; // failed to allocate memory
    }

    fibonacci_sequence[0] = 0;
    if (n > 0) {
        fibonacci_sequence[1] = 1;
    }

    for (i = 2; i <= n; ++i) {
        fibonacci_sequence[i] = fibonacci_sequence[i - 1] + fibonacci_sequence[i - 2];
        __VERIFIER_assert(fibonacci_sequence[i] >= fibonacci_sequence[i - 1]); // The sequence is non-decreasing
    }

    printf("Fibonacci sequence up to term %d:\n", n);
    for (i = 0; i <= n; ++i) {
        printf("%d ", fibonacci_sequence[i]);
    }
    printf("\n");

    free(fibonacci_sequence); // free the allocated memory
    return 0;
}