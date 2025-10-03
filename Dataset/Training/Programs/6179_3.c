#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_example.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

_Bool __VERIFIER_nondet_bool();
int __VERIFIER_nondet_int();

int main() {
    int x = 0;
    int y = 0;
    int z = 0;

    while (x < 100) {
        if (__VERIFIER_nondet_bool()) {
            if (y < 50) {
                y += 2;
            } else {
                y = 0;
            }
        } else {
            z += 3;
        }

        if (z > 200) {
            z = 0;
            x += 10;
        }
    }

    __VERIFIER_assert(z >= 0 && z <= 200);

    printf("Finished!\n");

    return 0;
}