#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "proposed_program.c", 7, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

unsigned int fibonacci(unsigned int n) {
    unsigned int a = 0, b = 1, c, i;
    if (n == 0) {
        return a;
    }
    if (n == 1) {
        return b;
    }

    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main(void) {
    unsigned int n = 10; // We compute the 10th Fibonacci number
    unsigned int result = fibonacci(n);

    // Assert that the result is the 10th Fibonacci number
    __VERIFIER_assert(result == 55); // The 10th Fibonacci number is 55

    printf("Fibonacci number F(%u) = %u\n", n, result);

    return 0;
}