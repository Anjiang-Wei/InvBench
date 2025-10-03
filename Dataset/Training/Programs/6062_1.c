#include <stdbool.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "program.c", 3, "reach_error"); }

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

int __VERIFIER_nondet_int();
_Bool __VERIFIER_nondet_bool();

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0);
    assume_abort_if_not(N <= 1000);

    int x = 0;
    int y = 0;

    for (int i = 0; i < N; i++) {
        _Bool c = __VERIFIER_nondet_bool();

        if (c) {
            x = x + 1;
        } else {
            y = y + 1;
        }
    }

    int total = x + y;
    __VERIFIER_assert(total == N);

    return 0;
}