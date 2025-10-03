#include <assert.h>
extern void abort(void);
void reach_error() { assert(0); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

#define MAX_ITERATIONS 100

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();

    // Assume some non-deterministic conditions
    if (a <= 0 || b <= 0 || c <= 0) {
        return 0;
    }

    int x = a, y = b, z = c;
    int iterations = 0;

    while (x > 0 && y > 0 && z > 0 && iterations < MAX_ITERATIONS) {
        // Perform some transformations
        x = x - y;
        y = y - z;
        z = z - a;

        // Reset values if they go too low to prevent negative spiral
        if (x < y) {
            x = a;
        }
        if (y < z) {
            y = b;
        }
        if (z < x) {
            z = c;
        }

        iterations++;
    }

    // Check postconditions
    __VERIFIER_assert(iterations <= MAX_ITERATIONS);

    return 0;
}