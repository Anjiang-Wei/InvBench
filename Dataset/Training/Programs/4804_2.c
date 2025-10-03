#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "new_program.c", 6, "reach_error");
}

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

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    int x = 0, y = 1;
    int i;
    for (i = 2; i <= n; i++) {
        int temp = x + y;
        x = y;
        y = temp;
    }
    return y;
}

int main() {
    int input = __VERIFIER_nondet_int();
    assume_abort_if_not(input >= 0 && input <= 45); // assume n is within a reasonable range

    int result = fibonacci(input);

    // Let's verify some basic behavior properties:
    if (input >= 2) {
    }
    if (input == 1) {
        __VERIFIER_assert(result == 1);
    }

    return 0;
}