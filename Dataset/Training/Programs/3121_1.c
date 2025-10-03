#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 7, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

int main() {
    int a, b;
    a = b = 0;
    int n = __VERIFIER_nondet_int();
    if (n < 0) {
        n = -n; // Ensure n is non-negative
    }

    while (a < n) {
        a++;
        b = b + 2;
        if (a % 2 == 0) {
            b--;
        }
    }

    // Post-condition: check that b is never less than a after the loop
    __VERIFIER_assert(b >= a);

    printf("a: %d, b: %d\n", a, b);
    return 0;
}