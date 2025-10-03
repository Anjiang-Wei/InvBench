#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = 0;
    int iterations = 0;

    // Assume initial conditions
    if (a < 0 || b < 0 || a > 100 || b > 100) {
        return 0; // Exit if the assumptions aren't met
    }

    // Main computation loop, ensure both variables move towards their sum
    while (iterations < 50) {
        iterations++;
        if (a > b) {
            a -= 2;
            c += 1; // Increment c to track operations
        } else if (b > a) {
            b -= 2;
            c += 1;
        } else {
            break; // Exit if they are equal
        }
    }

    // Ensure some properties post-computation
    __VERIFIER_assert((a >= 0 && b >= 0) || c > 0);

    return 0;
}