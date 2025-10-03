#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_example.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

unsigned int __VERIFIER_nondet_uint();
int __VERIFIER_nondet_int();

// Hypothetical function
int is_prime(int n) {
    if (n < 2) {
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    unsigned int x = __VERIFIER_nondet_uint();
    unsigned int y = 0;

    while (x > 0) {
        if (is_prime(x)) {
            y = x;
        }
        x--;
    }

    // Ensure the result is correct
    if (y > 0) {
        __VERIFIER_assert(is_prime(y));
    }

    return 0;
}