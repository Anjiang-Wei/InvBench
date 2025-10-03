#include <assert.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();
    int sum = 0;

    // Ensure n is within a reasonable range for testing
    if (!(n >= 0 && n <= 50)) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        // Adding a sequence of numbers where
        // toggle behavior depends on a random choice
        if (i % 2 == 0) {
            sum += a;
        } else {
            sum += b;
        }
    }

    // Check that sum is now non-negative if both are non-negative,
    // or some other property you are interested in summing these values.
    if (a >= 0 && b >= 0) {
        __VERIFIER_assert(sum >= 0);
    }

    return 0;
}