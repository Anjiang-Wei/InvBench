#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int __VERIFIER_nondet_int() {
    return rand() % 10 - 5; // Nondeterministically returns a small value between -5 and 4
}

int main(void) {
    int x = 0;
    int y = 0;

    // A loop that modifies x and y based on some conditions
    for (int i = 0; i < 10; i++) {
        int n = __VERIFIER_nondet_int();
        if (n > 0) {
            x += n;
            y -= n;
        } else {
            x -= n;
            y += n;
        }
    }

    // Ensure that x and y are balanced within a certain predictable relationship
    __VERIFIER_assert((x + y) == 0);

    return 0;
}