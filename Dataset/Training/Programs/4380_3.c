// Example program for verification and analysis

#include <assert.h>
extern void abort(void);
void reach_error() { assert(0); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
}

int main() {
    int a = 0, b = 0, n;
    n = __VERIFIER_nondet_int();

    // Ensure n is positive to make loops meaningful
    if (!(n > 0)) {
        return 0;
    }

    while (a < n) {
        b = 0;
        while (b < n) {
            if (b % 2 == 0) {
                a += 1;
            }

            b += 1;
        }

        a -= 1; // Simulate some decrement logic
        __VERIFIER_assert(a >= 0);
    }
}