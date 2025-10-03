#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { assert(0); }

extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}
extern _Bool __VERIFIER_nondet_bool();
extern int __VERIFIER_nondet_int();

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int x = 0, y = 0, limit;

    limit = __VERIFIER_nondet_int();
    assume_abort_if_not(limit > 0 && limit < 100);

    while (x < limit && y < limit) {
        if (__VERIFIER_nondet_bool()) {
            if (x < limit) {
                x += 2;
            }
        }

        if (__VERIFIER_nondet_bool()) {
            if (y < limit) {
                y += 3;
            }
        }

        if (x == y) {
            x++;
        }
    }

    __VERIFIER_assert(x != y);

    printf("x: %d, y: %d\n", x, y);

    return 0;
}