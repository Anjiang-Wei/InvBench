#include <stdio.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 4, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 1);
    assume_abort_if_not(b >= 0);

    int i = 0;
    int sum = 0;
    int product = 1;

    while (i < 10) {
        sum += a;
        product *= b + 1; // Ensure product does not become zero
        i++;
    }

    // Check if the operations are correct
    __VERIFIER_assert(sum == a * 10);

    return 0;
}