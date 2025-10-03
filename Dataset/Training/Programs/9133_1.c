#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "your_program.c", 14, "reach_error");
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
    int x = 0;
    int y = 0;

    // Condition: x must reach 10 and y should equal x * 2 at that point
    while (x < 10) {
        x++;
        y += 2;

        // Ensuring y is always even and twice the value of x during the loop
        __VERIFIER_assert(y == 2 * x);
    }

    // Check final state: x must be 10, and y must be 20 after exiting the loop.
    if (x == 10 && y == 20) {
        printf("Success: x is 10 and y is 20.\n");
    } else {
        reach_error();
    }

    return 0;
}