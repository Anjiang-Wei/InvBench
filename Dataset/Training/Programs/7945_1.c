#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example_program.c", 3, "reach_error"); }

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

int main() {
    int a = 0;
    int b = 5;
    int c = 10;
    int n = __VERIFIER_nondet_int();

    if (n <= 0) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        a += (b - i);

        for (int j = 0; j < 5; j++) {
            c -= (i + j);
            if (c < 0) {
                c = 10; // reset c
            }
        }
    }

    // Ensure a logical condition
    __VERIFIER_assert(c <= 10 && c >= 0);

    printf("Final values: a=%d, c=%d\n", a, c);

    return 0;
}