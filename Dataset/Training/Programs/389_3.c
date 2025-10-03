#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 5, "reach_error"); }

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
}

int calculate_series(int n, int x, int y) {
    int prev1 = x, prev2 = y;
    int current;

    if (n == 0) {
        return prev1;
    }
    if (n == 1) {
        return prev2;
    }

    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2;
        prev1 = prev2;
        prev2 = current;
    }
    return current;
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 20);

    int x = 1; // Initial value 1
    int y = 2; // Initial value 2

    int result = calculate_series(n, x, y);

    // Verify if result follows the series property for the first few numbers
    if (n == 0) {
    } else if (n == 1) {
    } else if (n == 2) {
        __VERIFIER_assert(result == 3); // 1 + 2
    } else if (n == 3) {
        __VERIFIER_assert(result == 5); // 2 + 3
    } else if (n == 4) {
        __VERIFIER_assert(result == 8); // 3 + 5
    }

    return 0;
}