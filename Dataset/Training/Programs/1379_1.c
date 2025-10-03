#include <assert.h>
#include <stdio.h>

extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}
extern int __VERIFIER_nondet_int(void);

int main() {
    int a = __VERIFIER_nondet_int(); // Some nondeterministic initial value for `a`
    int b = 0;
    int c = 1;

    // Ensure a starts within a realistic range to prevent undefined behavior.
    if (a < 0 || a > 1000) {
        return 0;
    }

    while (a < 10) {
        if (a % 2 == 0) {
            b += a;                     // Accumulate `a` into `b` when `a` is even
            c *= 2;                     // Double `c` every time
            __VERIFIER_assert(b < 100); // `b` should be less than 100 within the loop
        } else {
            b += 2; // Add an extra 2 to `b` when `a` is odd
        }

        a++;
    }

    // Post condition: After the loop `b` is no less than `a` + 5

    printf("Final values: a=%d, b=%d, c=%d\n", a, b, c);

    return 0;
}