#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 6, "reach_error"); }

int __VERIFIER_nondet_int(void) {
    return rand() % 20 - 10; // Returns a nondeterministic integer between -10 and 9
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    int a = 5;
    int b = 10;
    int x = 0, y = __VERIFIER_nondet_int();

    if (y <= 0) {
        return 0;
    }

    for (int i = 0; i < 10; i++) {
        x += a;

        if (x > 50) {
            x -= b;
            __VERIFIER_assert(x <= 50);
        }
    }

    // Additional check outside the loop
    if (y > 0) {
    }

    printf("Final value of x: %d\n", x);
    return 0;
}