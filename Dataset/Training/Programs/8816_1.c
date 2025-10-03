// This program is inspired by the SV-Benchmarks collection and contains computational logic
// that can be verified by automated verification tools.

#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int a = 0;
    int b = 1;

    // Assuming nondeterministic steps
    int steps = __VERIFIER_nondet_int();
    if (steps <= 0) {
        return 1;
    }
    if (steps > 1000) {
        steps = 1000; // limit steps to ensure termination
    }

    // Loop with computational logic
    for (int i = 0; i < steps; i++) {
        a = a + b;
        b = b * 2;
        if (b > 1000) {
            break; // Prevent overflow and stop the loop if b becomes too large
        }
    }

    __VERIFIER_assert(a <= 2000000); // Property to verify
    return 0;
}