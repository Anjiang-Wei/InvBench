#include <assert.h>
void reach_error() { assert(0); }

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
}

int main() {
    int n = __VERIFIER_nondet_int(); // Non-deterministic input
    int m = __VERIFIER_nondet_int(); // Non-deterministic input
    int a = 0, b = 0, c = n;

    assume_abort_if_not(m > 0);
    assume_abort_if_not(n >= 0);

    // Ensuring a trivially true condition before entering the loop
    assume_abort_if_not(a == 0 && b == 0 && c == n);

    // A loop with a specific pattern similar to increment and decrement
    while (c > 0) {
        b += c % m; // Add modulus result to b, mimicking some kind of computation
        c = c - m;  // Decrement c, here characterized by steps of m
        a += 1;     // Increment a as a counter
    }

    // Post-loop invariant verification
    // Ensures that after the loop, "a" correctly reflects the count of decrements by m
    //  and "c" reaches 0 or below, while b has some computational artifacts
    __VERIFIER_assert(a * m + c == n); // Ensuring total decreasing is valid

    return 0;
}