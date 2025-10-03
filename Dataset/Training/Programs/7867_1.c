#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "your_program.c", 5, "reach_error"); }
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

int calculate(int a, int b, int c) {
    return (a * b + c) % 10;
}

void loop_operations(int *x, int *y, int loop_bound) {
    int i;
    for (i = 0; i < loop_bound; ++i) {
        *x = calculate(*x, i, *y);
        *y = calculate(*y, *x, i);
        __VERIFIER_assert(*x >= 0 && *y >= 0);
    }
}

int main() {
    int a, b, c, result;
    int loop_bound;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    c = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && b >= 0 && c >= 0);

    loop_bound = 10; // Example fixed loop bound for demonstration

    int x = calculate(a, b, c);
    int y = calculate(c, a, b);

    loop_operations(&x, &y, loop_bound);

    result = calculate(x, y, a);

    printf("Result: %d\n", result);

    return 0;
}