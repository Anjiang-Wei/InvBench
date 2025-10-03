#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }

// A function to simulate nondeterministic integer inputs
int __VERIFIER_nondet_int(void) {
    return rand() % 100; // Random integer between 0 and 99
}

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

int main() {
    int m, n, p, q;
    int sum = 0;

    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();
    p = __VERIFIER_nondet_int();
    q = __VERIFIER_nondet_int();

    assume_abort_if_not(m >= 0 && m <= 50);
    assume_abort_if_not(n >= 0 && n <= 50);
    assume_abort_if_not(p >= 0 && p <= 50);
    assume_abort_if_not(q >= 0 && q <= 50);

    // Using a loop to model a process over these variables
    for (int i = 0; i < 100; i++) {
        sum += m + n;

        if (i % 20 == 0) {
            p += 1;
            q -= 1;

            if (q < 0) {
                q = 0;
            }
        }

        __VERIFIER_assert(p >= 0 && q >= 0);
    }

    // Check some properties after the loop

    printf("Loop completed with sum: %d, p: %d, q: %d\n", sum, p, q);

    return 0;
}