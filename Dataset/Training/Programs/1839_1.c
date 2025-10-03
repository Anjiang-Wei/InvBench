#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 10, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int __VERIFIER_nondet_int(void);

int main() {
    int a, b, n;
    int x = 0, y = 0, z = 1;

    n = __VERIFIER_nondet_int();
    if (n <= 0 || n > 10) {
        return 0;
    }

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    if (a < 0 || a > 100 || b < 0 || b > 100) {
        return 0;
    }

    while (x < n) {
        if (x % 2 == 0) {
            y = y + a;
        } else {
            y = y + b;
        }

        if (y > 500) {
            y = y - z;
        }

        z = z + 1;
        x = x + 1;
    }

    // Verifying that after the loop, x should always be equal to n.
    __VERIFIER_assert(x == n);

    printf("Program completed with: x=%d, y=%d, z=%d\n", x, y, z);
    return 1;
}