#include <stdio.h>
#include <stdlib.h>

extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main(void) {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0 && b >= 0 && c >= 0);

    int result = 0;
    int count = 0;

    while (count < a + b + c) {
        count++;
        result += 2;
    }

    __VERIFIER_assert(result == 2 * (a + b + c));

    printf("Result: %d\n", result);
    return 0;
}