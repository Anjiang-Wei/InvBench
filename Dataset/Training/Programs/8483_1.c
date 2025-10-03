#include <stdlib.h>

// Function declarations for verification
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 9, "reach_error"); }
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
    // Initialize variables
    int n = __VERIFIER_nondet_int();
    if (n <= 0) {
        return 0;
    }

    int x = 0;
    int y = 0;
    int z = 0;

    assume_abort_if_not(n < 1000);

    // Loop to perform computations based on even and odd conditions
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            x += 2;
            y += 3;
        } else {
            x += 3;
            y += 2;
        }
    }

    // Ensuring our condition holds at the end of the loop
    z = x + y;

    // Assert for verification
    __VERIFIER_assert(z == 5 * n);

    return 0;
}