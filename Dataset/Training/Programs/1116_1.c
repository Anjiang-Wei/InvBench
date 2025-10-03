#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern int __VERIFIER_nondet_int();
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 3, "reach_error"); }

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

int calculate(int x, int y) {
    int result = 0;
    for (int i = 0; i < 10; i++) {
        if ((x + y + i) % 3 == 0) {
            result += i;
        } else if ((x - y - i) % 2 == 0) {
            result -= i;
        }
    }
    return result;
}

int main() {
    int a, b;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0 && a <= 100);
    assume_abort_if_not(b >= 0 && b <= 100);

    int value = calculate(a, b);

    // Assert that the value should be within a certain range
    __VERIFIER_assert(value >= -45 && value <= 45);

    return 0;
}