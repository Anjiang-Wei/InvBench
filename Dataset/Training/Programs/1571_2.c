#include <stdbool.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 7, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int calculate_factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int x;
    x = __VERIFIER_nondet_int();
    assume_abort_if_not(x >= 0 && x <= 10); // Restrict values of x to prevent overflow

    int factorial = calculate_factorial(x);

    // Perform another computation based on factorial
    int sum = 0;
    int i = 1;
    while (i <= factorial) {
        sum += i;
        i++;
    }

    __VERIFIER_assert(sum >= factorial);

    return 0;
}