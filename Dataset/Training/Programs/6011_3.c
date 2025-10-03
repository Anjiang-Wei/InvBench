#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 4, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();
    int x = 0, y = 0;

    // Precondition
    if (!(a > 0 && b > 0 && c > 0 && a < 100 && b < 100 && c < 100)) {
        return 0;
    }

    while (a > 0 && b > 0) {
        _Bool flag = __VERIFIER_nondet_bool();
        if (flag) {
            x += a;
            a--;
        } else {
            y += b;
            b--;
        }
        if (x > 1000 || y > 1000) {
            break;
        }
    }

    // Another computation involving c
    int z = 1;
    for (int i = 0; i < c; ++i) {
        z *= 2;
        if (z > 1000) {
            break;
        }
    }

    __VERIFIER_assert(z >= 1);

    printf("x: %d, y: %d, z: %d\n", x, y, z);
    return 0;
}