#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 10, "reach_error"); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int a, b, c;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    c = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0 && a <= 100);
    assume_abort_if_not(b >= 0 && b <= 100);
    assume_abort_if_not(c >= 0 && c <= 100);

    int sum = 0;
    int condition = a + b > c; // Example constraint condition

    for (int i = 0; i < 10; i++) {
        if (condition) {
            sum += i;
        } else {
            sum -= i;
        }
    }

    // Verification condition: if a + b > c, then sum should be non-negative
    __VERIFIER_assert(!(condition) || (sum >= 0));

    printf("Sum: %d\n", sum);
    return 0;
}