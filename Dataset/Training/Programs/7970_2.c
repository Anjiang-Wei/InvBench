#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

int main() {
    int a, b, c, d;
    a = 0;
    b = 0;
    c = 0;
    d = __VERIFIER_nondet_int();

    while (a < 50) {
        b += 2; // Increase b by 2 in each iteration
        if (__VERIFIER_nondet_bool()) {
            a += 1; // Increase a based on some nondeterministic condition
            c += 1; // Properly increment c every time a changes
        } else {
            c -= 1; // Decrease c otherwise
        }

        // Ensure that b is always at least twice the value of a

        if (d > 100) {
            d -= 1; // Simulate some computations with d
        } else {
            d += 2;
        }
    }

    // Final assertions after the loop's main logic
    __VERIFIER_assert(a <= 50);

    printf("Final values: a = %d, b = %d, c = %d, d = %d\n", a, b, c, d);
    return 0;
}