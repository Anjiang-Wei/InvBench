#include <stdio.h>

// Function to simulate non-deterministic integer values
extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void reach_error(void) {
    printf("Error reached!\n");
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
        abort();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0 && b >= 0 && c >= 0); // Assume all inputs are non-negative

    int sum = 0;
    int count = 0;
    int max_iterations = 100;

    // Main loop: iterate until we reach at least max_iterations or another condition is met
    while (count < max_iterations && sum < (a + b + c)) {
        if (a > b && a > c) {
            sum += a;
            a--; // Decrease a to simulate progression
        } else if (b > c) {
            sum += b;
            b--; // Decrease b to simulate progression
        } else {
            sum += c;
            c--; // Decrease c to simulate progression
        }
        count++;
    }

    // Final assertion to verify some post-condition
    __VERIFIER_assert(sum >= a + b + c);

    // Optional: Print final values for debugging
    printf("Final values => a: %d, b: %d, c: %d, sum: %d, count: %d\n", a, b, c, sum, count);

    return 0;
}