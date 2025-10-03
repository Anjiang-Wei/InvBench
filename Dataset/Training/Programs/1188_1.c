// This program checks the property of a number sequence
// GENERATED FOR VERIFICATION PURPOSES

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() {
    abort();
}

extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
    }
    }
    return;
}

int main(void) {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();

    // Assume some constraints to make the problem manageable for verification
    if (!(a > 0 && b > 0 && n > 0 && a <= 100 && b <= 100 && n <= 100)) {
        return 0;
    }

    int x = a;
    int y = b;
    int step = 0;

    // The loop will run 'n' steps, calculating a sequence
    while (step < n) {
        int temp = x;
        x = y;
        y = temp + y; // Fibonacci-like sequence
        step++;
    }

    // We assert that x and y are still positive, which should hold if 'a' and 'b' are positive
    __VERIFIER_assert(x > 0 && y > 0);

    // Additional property: x should not exceed a large number (arbitrarily chosen for this example)

    return 0;
}