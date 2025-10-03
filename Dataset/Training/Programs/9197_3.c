#include <assert.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int a, b, n;
    a = 0;
    b = 0;
    n = __VERIFIER_nondet_int();

    // Ensure n is positive for meaningful computation
    if (n < 1) {
        n = 1;
    }

    while (b < n) {
        b++;
        a += 2 * b; // Simulate some computational logic

        // Check conditions related to the computation
        if (b < n / 2) {
        } else {
        }
    }

    __VERIFIER_assert(a >= b * 2); // Final condition check

    return 0;
}