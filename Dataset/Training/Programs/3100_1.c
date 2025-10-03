#include <stdio.h>
#include <stdlib.h>

// Function prototypes
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 5, "reach_error"); }

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

extern int __VERIFIER_nondet_int(void);

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0 && N <= 46); // limit to prevent integer overflow

    int a = 0, b = 1, c, i;
    for (i = 0; i < N; i++) {
        if (i > 1) {
            c = a + b;
            a = b;
            b = c;
        }
    }

    // Check property: Fibonacci numbers at even index are strictly non-negative
    if (N % 2 == 0) {
        __VERIFIER_assert(b >= 0);
    }

    // Check another property: Fibonacci numbers are non-negative

    printf("Fibonacci number at index %d is %d\n", N, b);
    return 0;
}