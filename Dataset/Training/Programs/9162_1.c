#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

#define MAX 1000

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

// A function to simulate a check on a condition
int check_condition(int a, int b, int c) {
    return (a * a + b * b == c * c);
}

int main() {
    int a, b, c, n;
    a = b = c = 0;

    n = __VERIFIER_nondet_int(); // Simulate an arbitrary input size
    assume_abort_if_not(n > 0 && n < MAX);

    // Simulate searching for natural numbers a, b, c which should satisfy a known condition: Pythagorean triple
    for (a = 1; a <= n; a++) {
        for (b = a; b <= n; b++) {
            // Calculating c based on a and b
            c = a * a + b * b;

            // Ensure c is a perfect square
            for (int k = 1; k <= (a + b); k++) {
                if (k * k == c) {
                    // When c is found to be a perfect square, we found a Pythagorean triple
                    // Pythagorean triple: a^2 + b^2 = c^2
                    __VERIFIER_assert(check_condition(a, b, k) == 1);

                    // Print found Pythagorean triple
                    printf("Found Pythagorean triple: (%d, %d, %d)\n", a, b, k);
                }
            }
        }
    }

    return 0;
}