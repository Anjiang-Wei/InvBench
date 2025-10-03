#include <stdio.h>

// Assume external functions for verification similar to the examples
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 4, "reach_error"); }
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
    return;
}

int main() {
    int a, b, result, i;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Assume constraints
    assume_abort_if_not(a >= 1);
    assume_abort_if_not(b >= 1 && b < 10);

    // Some incremental and decremental computations
    result = 0;
    i = 0;

    while (i < 10) {
        result += a * b;
        __VERIFIER_assert((result - (a * b * (i + 1))) == 0);

        if (result > 100) {
            break; // early termination
        }

        i++;
    }

    // Some postcondition's arbitrary requirement/asserting an expected property

    printf("Final result is %d\n", result);
    return 0;
}