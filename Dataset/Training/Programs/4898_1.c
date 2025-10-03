#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }

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
    unsigned long long a = 1;
    unsigned long long b = 1;
    unsigned int n = 10; // Fibonacci number to compute
    unsigned int i = 2;

    while (i < n) {
        unsigned long long tmp = b;
        b = a + b;
        a = tmp;
        i++;
    }

    // Asserting that the 10th Fibonacci number is correct
    __VERIFIER_assert(b == 55);

    printf("The 10th Fibonacci number is %llu\n", b);

    return 0;
}