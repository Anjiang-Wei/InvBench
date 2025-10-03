#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a, b, c;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Initial assumptions about a and b
    assume_abort_if_not(a >= 1 && a <= 20);
    assume_abort_if_not(b >= 1 && b <= 20);

    int i = 0;
    int sum = 0;

    // Loop iterating a fixed number of times
    while (i < 10) {
        sum += a + b;
        i++;
    }

    c = sum / 10;

    // Verification of the condition
    __VERIFIER_assert(c == (a + b));
    printf("Final value of c = %d\n", c);

    return 0;
}