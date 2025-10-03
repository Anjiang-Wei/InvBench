#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 6, "reach_error"); }
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
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    unsigned int a = 0, b = 1, temp;
    for (unsigned int i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main() {
    unsigned int n = 8; // Let's compute the 8th fibonacci number
    unsigned int result = 0;
    unsigned int i = 0;

    while (i <= n) {
        result = fibonacci(i);
        i++;
    }

    if (n == 8) {
        __VERIFIER_assert(result == 21); // Fibonacci(8) = 21
    }

    printf("Fibonacci(%u) = %u\n", n, result);

    return 0;
}