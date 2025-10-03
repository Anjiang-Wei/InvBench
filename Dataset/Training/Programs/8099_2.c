#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int x = 0;
    int y = __VERIFIER_nondet_int();
    int z = __VERIFIER_nondet_int();

    if (y >= 0 && y <= 1000 && z >= 0 && z <= 1000) {
        int i = 0;

        while (i < y) {
            x += z;
            i++;
            if (x > 10000) {
                break;
            }
        }

        if (y > 0) {
        } else {
            __VERIFIER_assert(x == 0);
        }
    }
    return 0;
}