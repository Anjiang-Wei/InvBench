#include <assert.h>
#include <stdio.h>

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void reach_error(void) { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

static const int MAX_VALUE = 100;

int main() {
    int a = 0, b = 0, c = 0;

    // Non-deterministically choose a starting value for each integer variable.
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    c = __VERIFIER_nondet_int();

    // Assume initial constraints on the values
    if (a < 0 || a > MAX_VALUE || b < 0 || b > MAX_VALUE || c < 0 || c > MAX_VALUE) {
        return 0;
    }

    while (__VERIFIER_nondet_bool()) {
        if (__VERIFIER_nondet_bool()) {
            if (a < MAX_VALUE) {
                a += 2;
            }
        }

        else {
            if (__VERIFIER_nondet_bool() && b > 0) {
                b -= 1;
            } else {
                b += 3;
            }
        }

        // Using c to adjust values of a and b based on certain conditions
        if (c % 4 == 0) {
            a = (a + b) % MAX_VALUE;
        } else if (c % 5 == 0) {
            b = (b + c) % MAX_VALUE;
        } else {
            c = (c + 5) % MAX_VALUE;
        }

        // Verify constraint conditions after each iteration
        __VERIFIER_assert(c >= 0 && c <= MAX_VALUE);
    }
    return 0;
}