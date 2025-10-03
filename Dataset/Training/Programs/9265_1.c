#include <stdio.h>

// Custom abort mechanism (simulated for non-linux systems)
void abort(void) {
    printf("Program aborted.\n");
    exit(1);
}

// Custom assertion to catch errors
void reach_error() {
    printf("Assertion failed.\n");
    abort();
}

// Simulating nondeterministic integer value
extern int __VERIFIER_nondet_int(void);

// Custom function to simulate assumption failure
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Custom assertion to verify conditions
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

// Function to simulate a nondeterministic integer
int __VERIFIER_nondet_int() {
    static int counter = 0;
    return ++counter; // Returns an increasing sequence of numbers
}

int main() {
    int m, n, a, b, c;
    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    // Ensure m and n are within a reasonable range to simulate bounded nondeterminism
    assume_abort_if_not(m > 0 && m < 100);
    assume_abort_if_not(n > 0 && n < 100);

    a = 0;
    b = 0;
    c = 0;

    while (a < m || b < n) {
        if (a < m) {
            a++;
            c += a;
        }
        if (b < n) {
            b++;
            c += b;
        }

        // Verify that c is equal to the sum of the series 1 to a and 1 to b
        __VERIFIER_assert(c == (a * (a + 1) / 2) + (b * (b + 1) / 2));
    }

    return 0;
}