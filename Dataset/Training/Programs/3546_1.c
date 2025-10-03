#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int compute(int, int);
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 6, "reach_error"); }
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

// Start of the main program
int main() {
    int a, b, result;
    long long x, y, sum;

    // Initialize with nondeterministic values
    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && a <= 10);
    b = __VERIFIER_nondet_int();
    assume_abort_if_not(b >= 0 && b <= 10);

    x = a;
    y = b;
    sum = 0;

    // Loop similar to Example Program 2
    while (1) {
        __VERIFIER_assert(sum == (long long)a * b - y * x);
        if (!(y != 0)) {
            break;
        }

        if (y % 2 == 1) {
            sum = sum + x;
            y = y - 1;
        }
        x = 2 * x;
        y = y / 2;
    }

    // Incremental computation with constraints
    result = compute(a, b);

    return 0;
}

// Function to perform a computation
int compute(int a, int b) {
    int c = 0;
    int i = 0;
    while (i < a) {
        c += b;
        if (c > 50) {
            return -1; // Return an error condition
        }
        i++;
    }
    return c;
}