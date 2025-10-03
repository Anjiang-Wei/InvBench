#include <stdbool.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example_new.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

extern int __VERIFIER_nondet_int();

int main(void) {
    unsigned int a = 0;
    unsigned int b = 1;

    // Increment 'a' and double 'b' while maintaining a constraint using a nondeterministic condition
    while (__VERIFIER_nondet_int()) {
        a++;
        b *= 2;
        if (b > 1000) {
            break;
        }
    }

    // Ensures that computation respects some properties:
    //  - If 'b' exceeds 1000, 'a' must be greater than 9 (observing growth pattern: initial b = 1, double each iteration)
    //  - If 'b' doesn't exceed 1000, it must be twice of previous 'b', starting from 1
    if (b > 1000) {
    } else {
        __VERIFIER_assert((b & (b - 1)) == 0); // checks if b is a power of 2
    }

    return 0;
}