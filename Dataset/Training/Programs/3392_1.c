#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
extern void abort(void);
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
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N >= 1 && N < 100);

    int x = 0, y = 0;

    // Start off a computation pattern
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            x += i;
        } else {
            y += i;
        }
    }

    // Analytical condition after loop
    int diff = x - y;

    // Make sure the abs difference is less than N
    __VERIFIER_assert(diff <= N);

    printf("Computation completed with x: %d, y: %d, diff: %d\n", x, y, diff);

    return 0;
}