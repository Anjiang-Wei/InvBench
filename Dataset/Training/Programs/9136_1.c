#include <assert.h>

extern int __VERIFIER_nondet_int(void);
extern void __VERIFIER_error(void) __attribute__((__noreturn__));

void reach_error() {
    __VERIFIER_error();
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int sum = 0;

    // Precondition: a must be non-negative and less than 100
    if (a < 0 || a > 100) {
        return 0;
    }

    // Precondition: b must be non-negative and less than 100
    if (b < 0 || b > 100) {
        return 0;
    }

    // A simple multiplication using a loop
    for (int i = 0; i < b; i++) {
        sum += a;
    }

    // We assume that when both `a` and `b` are less than 50, the sum should be less than 2500
    // This creates a condition that can be checked for correctness
    if (a < 50 && b < 50) {
        __VERIFIER_assert(sum < 2500);
    }

    return 0;
}