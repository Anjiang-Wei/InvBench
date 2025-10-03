#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "my_custom_program.c", 5, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

int main() {
    int a, b, factor, result;

    a = __VERIFIER_nondet_int();
    b = 5;
    factor = 2;
    result = 0;

    // Ensure a positive starting a
    assume_abort_if_not(a > 0);

    // Compute the series sum for a*factor^i, i=0..b-1
    for (int i = 0; i < b; i++) {
        result += a;
        a *= factor;

        // Ensure the result is never zero as a trivial check
        __VERIFIER_assert(result != 0);
    }

    // Check if the final step result makes sense

    printf("Result: %d\n", result);

    return 0;
}