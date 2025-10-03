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
extern unsigned int __VERIFIER_nondet_uint(void);

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
    int a, b;
    unsigned int n = __VERIFIER_nondet_uint();

    assume_abort_if_not(n > 0 && n < 100);

    a = 0;
    b = n;

    while (a < b) {
        a += 2; // Increases a by 2
        b -= 1; // Decreases b by 1
    }

    // Assert that a and b meet a specific relationship after the loop
    __VERIFIER_assert(a >= b && b >= 0 && a >= n - b);

    // Output the value of a and b after the loop
    printf("a: %d, b: %d\n", a, b);

    return 0;
}