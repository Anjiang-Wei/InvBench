#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

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
    int a = 0, b = 0, n = 0;
    n = __VERIFIER_nondet_int();
    if (n < 0) {
        return 0; // Ensure only positive iterations
    }

    for (int i = 0; i < n; i++) {
        if (i % 3 == 0) {
            a += 2;
        } else {
            b += 3;
        }
    }

    // Verify that a and b are non-negative and related by the loop conditions
    if (n % 3 == 0) {
    } else {
        __VERIFIER_assert(b >= ((n / 3) * 3));
    }

    printf("a: %d, b: %d\n", a, b);
    return 0;
}