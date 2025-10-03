#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 9, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();
    int steps = 0;
    int sum = 0;

    assume_abort_if_not(a >= 0 && a <= 50);
    assume_abort_if_not(b >= 0 && b <= 50);
    assume_abort_if_not(c >= 0 && c <= 10);

    while (steps < c) {
        sum += a + b;
        __VERIFIER_assert(sum >= a + b);

        if (sum > 100) {
            // To prevent overflow in a constrained environment
            sum -= 50;
        }

        a += 1;
        b -= 1;
        steps++;
    }

    assume_abort_if_not(sum <= 100);
    printf("Sum after %d iterations: %d\n", c, sum);
    return 0;
}