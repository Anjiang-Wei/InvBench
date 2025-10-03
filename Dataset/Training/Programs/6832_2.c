#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }

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
    int a = 0;
    int b = 1;
    int c = 2;
    int n;

    printf("Enter a positive integer n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input\n");
        return 1;
    }

    // Loop to simulate some progress in computation
    for (int i = 0; i < n; i++) {
        a += 1;
        b += a;
        c += b;
    }

    // Post loop condition verification
    __VERIFIER_assert(b >= n);

    printf("a: %d, b: %d, c: %d\n", a, b, c);
    return 0;
}