#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

int main() {
    int m = __VERIFIER_nondet_int();
    if (!(m > 0)) {
        return 0;
    }

    int sum = 0;
    int i = 0;

    while (i < m) {
        sum += __VERIFIER_nondet_int();

        if (sum >= 100) {
            break;
        }

        i++;
    }

    // Ensure the loop terminates with a meaningful condition
    if (sum < 100) {
    } else {
        __VERIFIER_assert(sum >= 100 && i <= m);
    }

    return 0;
}