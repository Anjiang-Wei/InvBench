#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
    return;
}

int __VERIFIER_nondet_int(void);

int main() {
    int n = __VERIFIER_nondet_int();
    int x = 0, y = 0;

    // Assume n is a positive number to make sure the loop runs.
    if (n <= 0) {
        return 0;
    }

    while (x < n) {
        x++;
        y += 2;
    }

    // After loop, x should be equal to n and y should be twice the value of n
    __VERIFIER_assert(y == 2 * n);

    printf("Final values are x: %d, y: %d\n", x, y);
    return 0;
}