#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "custom_verification.c", 7, "reach_error");
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

extern int __VERIFIER_nondet_int(void);

int complex_computation(int a, int b, int c) {
    if (a < 0 || b < 0 || c < 0) {
        return -1; // Invalid input
    }
    int result = 0;
    int i;
    for (i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            result += a * b;
        } else {
            result -= b * c;
        }
    }
    return result;
}

int condition_check(int x, int y) {
    if (x > y) {
        return 1;
    } else if (x < y) {
        return -1;
    } else {
        return 0;
    }
}

int main(void) {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();

    if (a < 0 || b < 0 || c < 0) {
        // Reject negative inputs
        return -1;
    }

    int comp_result = complex_computation(a, b, c);

    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();

    if (x < 0 || y < 0) {
        // Reject negative inputs
        return -1;
    }

    int check_result = condition_check(x, y);
    __VERIFIER_assert(check_result >= -1 && check_result <= 1);

    // Additional loop for more complexity
    int z = 0;
    int limit = 10;
    while (z < limit) {
        z++;
        if (z == 5) {
        }
    }

    return 0;
}