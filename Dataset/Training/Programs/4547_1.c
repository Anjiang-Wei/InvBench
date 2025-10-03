#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
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

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int a = 0, b = 0;
    int factor = 3;
    int limit = 5;

    assume_abort_if_not(factor > 0);

    while (a < limit) {
        a++;
        b += factorial(a);
    }

    // Check if the sum of factorials up to 5 is correct
    __VERIFIER_assert(b == 153); // 1! + 2! + 3! + 4! + 5! = 153

    printf("Factorial sum up to %d is %d\n", limit, b);

    return 0;
}