#include <assert.h>

// Function prototypes for error handling, assertions, and nondeterministic inputs
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 10, "reach_error"); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    // Initialize variables using nondeterministic values
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int z = 0;
    int iterations = 10;

    // Assume initial condition that may stem from problem constraints
    assume_abort_if_not(a > 0 && b > 0);

    // Loop with some logic that modifies values based on conditions
    for (int i = 0; i < iterations; i++) {
        if (a < b) {
            a += 3;
            b -= 2;
            z += 1; // Track operations on z
        } else {
            b += 2;
            a -= 1;
        }
    }

    // Check relationships and conditions after loop execution
    __VERIFIER_assert(a >= 0 && b >= 0 && z <= iterations);

    return 0;
}