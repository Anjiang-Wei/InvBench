#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_prog.c", 6, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);

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

int main() {
    int num, square, i;
    int factorial = 1;

    num = __VERIFIER_nondet_int();
    assume_abort_if_not(num > 0 && num <= 10);

    square = num * num;

    // Compute factorial of num
    for (i = num; i > 1; i--) {
        factorial *= i;
    }

    // Loop for some arbitrary computation
    for (i = 0; i < 5; i++) {
        square += i;
    }

    // Simple checks to verify computations
    __VERIFIER_assert(square >= num * num);

    printf("Number: %d, Square: %d, Factorial: %d\n", num, square, factorial);

    return 0;
}