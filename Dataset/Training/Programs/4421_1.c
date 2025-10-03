#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "custom_program.c", 5, "reach_error"); }

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

int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int x, y;
    int result;

    x = __VERIFIER_nondet_int();
    y = __VERIFIER_nondet_int();

    assume_abort_if_not(x >= 0 && x <= 10);
    assume_abort_if_not(y >= 0 && y <= 10);

    // Calculate factorial for verification
    result = factorial(x);

    // Simulate some meaningful logic
    if (x == y) {
        result += factorial(y);
    }

    // Constraints for verification
    assume_abort_if_not(result > 0);
    assume_abort_if_not(result >= x * y);

    // Loop behaving a conditionally linear growth
    while (x > 0) {
        x -= 2;
        result += x;
    }

    __VERIFIER_assert(result >= 0);

    printf("Result is: %d\n", result);
    return 0;
}