#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new-example.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int n;
    long long a, b, p;
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(n >= 0 && n <= 10);

    a = 1; // Represents the current term in the series and starts at 1
    b = 1; // Represents the sum of terms and starts at 1
    p = 1; // Multiplier starts at 1

    while (1) {
        __VERIFIER_assert(b == a * a); // Property that should hold in the loop
        if (!(p < n)) {
            break;
        }

        p++;
        a = a + 3; // Increment sequence based on some function
        b = a * a; // Update sum to be the square of the current term
    }
}