#include <assert.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

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
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();

    // Assume initial conditions
    if (x < 0 || y < 0) {
        return 0;
    }

    // Perform some computation
    int z = x * y;
    int triangle_sum = 0;

    for (int i = 0; i < x; i++) {
        triangle_sum += i;
        y += i;
    }

    // After the loop, ensure that y is non-negative
    __VERIFIER_assert(y >= 0);

    // Using the computed values to reach a conclusion
    if (z > 100) {
    } else {
    }

    return 0;
}