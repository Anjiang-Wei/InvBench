#include <assert.h>
#include <stdlib.h>

extern void reach_error(void) { assert(0); }
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

extern int __VERIFIER_nondet_int(void);

int main() {
    int a, b, c;

    // Initialize nondeterministic values
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Ensure valid starting conditions
    if (!(a >= 0 && b >= 0)) {
        return 0;
    }

    // Compute a nondeterministic input derived value for system state
    c = a + b;

    // Loop iterating through decreasing 'c' and increasing 'd'
    int d = 0;
    while (c > 0) {
        // Increment 'd' - mirrors some computing action while decreasing 'c'
        d += 2;
        c -= 1;
    }

    // Post-loop condition: 'd' should be twice the original sum of 'a + b'
    __VERIFIER_assert(d == 2 * (a + b));

    return 0;
}