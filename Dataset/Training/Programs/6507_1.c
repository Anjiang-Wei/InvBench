#include <stdbool.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "pattern_example.c", 7, "reach_error"); }

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
    unsigned int a = 1;
    unsigned int b = 2;
    unsigned int c = 1;
    unsigned int steps = 0;

    // Calculate the nth number in a sequence defined by: a_n = a_{n-1} + 2 * a_{n-2}
    while (c < 100) {
        unsigned int next = a + 2 * b;
        a = b;
        b = next;
        c = next;
        steps++;
    }

    // Check if steps taken were less than 10
    __VERIFIER_assert(steps < 10);

    printf("Final value: %u\n", c);
    printf("Steps taken: %u\n", steps);

    return 0;
}