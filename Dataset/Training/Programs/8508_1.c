#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 5, "reach_error"); }

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
}

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

int main() {
    int N = __VERIFIER_nondet_int();
    if (N <= 0) {
        return 1;
    }
    assume_abort_if_not(N < 100);

    int x = 0;
    int count = 0;
    while (count < N) {
        if (__VERIFIER_nondet_bool()) {
            x += 2;
        } else {
            x += 3;
        }
        count++;
    }

    int y = x;
    int result = 0;

    for (int i = 0; i < y; i++) {
        if (i % 2 == 0) {
            result += 1;
        } else {
            result -= 1;
        }
    }

    // The expectation here is that result should be 0 for even y and 1 or -1 for odd y
    if (y % 2 == 0) {
        __VERIFIER_assert(result == 0);
    } else {
    }

    return 0;
}