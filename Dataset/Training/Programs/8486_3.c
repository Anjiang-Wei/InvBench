#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "proposed.c", 4, "reach_error"); }

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
    int m = __VERIFIER_nondet_int();
    assume_abort_if_not(m >= 0 && m <= 100);
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 100);

    int result = 0;
    int i, j;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            result += i * j;
        }
    }

value_check:

    assume_abort_if_not(m % 2 == 0);
    int x = m / 2;
    int y = n / 2;

    int control = 0;
    while (x < m && y < n) {
        control += x * y;
        x++;
        y++;
    }

    __VERIFIER_assert(control >= 0);

    return 0;
}