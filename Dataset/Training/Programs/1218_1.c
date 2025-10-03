#include <assert.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "custom-program.c", 9, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int n, z;
    long long sum = 0, product = 1;

    n = __VERIFIER_nondet_int();
    z = __VERIFIER_nondet_int();

    assume_abort_if_not(n >= 1);
    assume_abort_if_not(z > 0);

    for (int i = 0; i < n; i++) {
        // Sum of first n integers
        sum += i;
        // Product growth with a factor of z
        product *= z;
        __VERIFIER_assert(sum < product || product >= z);
    }

    // Check if the difference between product and sum is a multiple of z

    return 0;
}