#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "new_program.c", 3, "reach_error");
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main(void) {
    unsigned int a = 1;
    unsigned int b = 0;
    unsigned int n = 10; // Loop runs for 10 times
    unsigned int count = 0;

    // An interesting loop that computes Fibonacci series
    while (count < n) {
        unsigned int temp = b;
        b = a + b;
        a = temp;
        count++;
    }

    // The Fibonacci of series of 10 iterations: 55
    __VERIFIER_assert(b == 55);

    return 0;
}