#include <stdbool.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    // Assume initial constraints
    assume_abort_if_not(b > 0);
    assume_abort_if_not(a >= 0);

    int sum = 0;

    // Iterates over modulo operation to sum remainders
    while (a > 0) {
        sum += a % b;
        a--;
    }

    // Conditions to verify
    __VERIFIER_assert(sum >= 0);

    // Print results for human verification
    printf("Sum of remainders: %d\n", sum);

    return 0;
}