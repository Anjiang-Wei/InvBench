#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 4, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void exit(int);

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

int calculate(int x) {
    int result = 1;
    for (int i = 0; i < x; i++) {
        result *= 2;
    }
    return result;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n < 30); // Constraint to keep the calculation within bounds

    int result = calculate(n);

    // Verify if the result is within a reasonable range
    __VERIFIER_assert(result > 0 && result < (1 << 30));

    // Additional constraint to ensure meaningful checks

    return 0;
}