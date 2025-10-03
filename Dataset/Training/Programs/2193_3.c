#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 6, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void exit(int);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int a = 0, b = 0, c = 0;
    int d = 0, e = 0, f = 0;
    int limit = 10; // constraint to limit the loop iterations
    int input;

    // Main computation loop
    for (int i = 0; i < limit; i++) {
        // Simulate nondeterministic input
        input = __VERIFIER_nondet_int();
        if ((input != 1) && (input != 2) && (input != 3)) {
            continue;
        }

        // Increment counters based on input
        if (input == 1) {
            a++;
            d += 2;
        } else if (input == 2) {
            b++;
            e += 3;
        } else if (input == 3) {
            c++;
            f += 4;
        }

        // Constraint conditions
        if (a > 2 && b > 2) {
        }

        if (d > 5 && e > 7) {
        }
    }

    // Final assertions
    __VERIFIER_assert(a + b + c >= 0);

    return 0;
}