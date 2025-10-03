#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 5, "reach_error"); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}
int __VERIFIER_nondet_int();

#define MAX_VAL 1000

int main() {
    int a = 0, b = 0, c = 0, count = 0;
    int n = __VERIFIER_nondet_int();

    if (n <= 0 || n > MAX_VAL) {
        return 0;
    }

    // Main computation loop
    while (count < n) {
        int choice = count % 3;
        switch (choice) {
        case 0:
            a += 2;
            break;
        case 1:
            b += 3;
            break;
        case 2:
            c += 4;
            break;
        }
        count++;

        // Assert that the sum satisfies a simple condition
        __VERIFIER_assert((a + b + c) >= (2 * count));
    }

    // Print result
    printf("Final Values: a=%d, b=%d, c=%d\n", a, b, c);
    return 0;
}