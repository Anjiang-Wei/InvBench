#include <assert.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 5, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

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

int max_value(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    int z = __VERIFIER_nondet_int();

    assume_abort_if_not(x >= 0);
    assume_abort_if_not(y >= 0);
    assume_abort_if_not(z >= 0);
    assume_abort_if_not(x <= 100);
    assume_abort_if_not(y <= 100);
    assume_abort_if_not(z <= 100);

    int max_value_found = -1;
    int i = 0;

    while (i < 3) {
        if (i == 0) {
            max_value_found = max_value(x, max_value_found);
        } else if (i == 1) {
            max_value_found = max_value(y, max_value_found);
        } else {
            max_value_found = max_value(z, max_value_found);
        }
        i++;
    }

    __VERIFIER_assert(max_value_found >= z);

    return 0;
}