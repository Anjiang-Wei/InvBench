#include <assert.h>
#include <stdbool.h>

extern void abort(void);
void reach_error() { assert(0); }
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
    int a, b, c, d, sum;
    int x, y;
    a = 0;
    b = 0;
    c = 0;
    d = 0;

    // Nondeterministic inputs
    x = __VERIFIER_nondet_int();
    assume_abort_if_not(x >= 0 && x <= 10);

    y = __VERIFIER_nondet_int();
    assume_abort_if_not(y >= 0 && y <= 10);

    // Calculate sum of squares for a range
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            a += i * i;
            b += j * j;
        }
    }
    sum = a + b;

    // A simple verification condition
    // Ensure that sum is always non-negative

    // Condition to check if the sum is exactly divisible by a number
    c = 5; // Arbitrary choice for divisor
    d = sum % c;
    __VERIFIER_assert(d >= 0 && d < c); // Ensures modulo logic is correct

    return 0;
}