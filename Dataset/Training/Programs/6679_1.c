#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "example.c", 5, "reach_error");
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

int main(void) {
    int x = 1000;
    int y = 2000;
    int z = 300;

    while (x > 0) {
        x -= 50;
        y += 20;

        if (x % 150 == 0) {
            z += 5;
        }
    }

    __VERIFIER_assert(y > z);

    return 0;
}